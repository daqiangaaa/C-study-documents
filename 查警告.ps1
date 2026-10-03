# 查警告.ps1 —— gcc 警告翻译器
# 用法一：双击 D:\cpp\查警告.bat（会读剪贴板里那一行编译输出）
# 用法二：D:\cpp\查警告.bat -Wmaybe-uninitialized
$ErrorActionPreference = 'Continue'
$enc = [System.Text.Encoding]::GetEncoding(936)
try { [Console]::OutputEncoding = $enc } catch {}
function GB([string]$s) { if ($null -eq $s) { return '' }; return $enc.GetString($enc.GetBytes($s)) }
function Say([string]$s) { Write-Host (GB $s) }

$TABLE = 'D:\cpp\警告翻译表.md'
if (-not (Test-Path $TABLE)) { Say "找不到 $TABLE"; exit 1 }

$lines = [System.IO.File]::ReadAllLines($TABLE, (New-Object System.Text.UTF8Encoding($false)))

# ---- 把表格切成 17 小节 ----
$secs = New-Object System.Collections.ArrayList
$title = $null; $body = $null
foreach ($x in $lines) {
    if ($x -like '### *') {
        if ($title) { [void]$secs.Add([pscustomobject]@{ Title = $title; Text = ($body -join "`n") }) }
        $title = $x; $body = New-Object System.Collections.ArrayList
    } elseif ($title) { [void]$body.Add($x) }
}
if ($title) { [void]$secs.Add([pscustomobject]@{ Title = $title; Text = ($body -join "`n") }) }

function NamesOf([string]$t) {
    $r = New-Object System.Collections.ArrayList
    foreach ($m in [regex]::Matches($t, '-W[A-Za-z][A-Za-z0-9-]*')) {
        if ($m.Value -eq '-Wall' -or $m.Value -eq '-Werror' -or $m.Value -eq '-Wextra') { continue }
        if (-not $r.Contains($m.Value)) { [void]$r.Add($m.Value) }
    }
    if ($r.Count -eq 0) { return '（没有 -W 名字）' }
    return $r
}
function Dash([string]$t) {
    $out = ''
    $inCode = $false
    foreach ($ln in ($t -split "`n")) {
        if ($ln.TrimStart().StartsWith('```')) { $inCode = -not $inCode; continue }
        if ($inCode) { continue }
        if ($ln -match '^\s*-\s') {
            $out = $out + "`n" + ($ln -replace '^\s*-\s*', '')
        } elseif ($ln.Trim() -ne '' -and $out -ne '') {
            $out = $out + ' ' + $ln.Trim()
        }
    }
    return $out.Trim()
}

# ---- 输入：参数优先，否则读剪贴板 ----
$text = ''
if ($args.Count -gt 0) { $text = ($args -join ' ') }
else { try { $text = (Get-Clipboard -Raw -ErrorAction Stop) } catch { $text = '' } }
if ($null -eq $text) { $text = '' }

$names = New-Object System.Collections.ArrayList
foreach ($m in [regex]::Matches($text, '-W[A-Za-z][A-Za-z0-9-]*')) {
    $v = $m.Value
    if ($v -eq '-Wall' -or $v -eq '-Werror' -or $v -eq '-Wextra') { continue }
    if (-not $names.Contains($v)) { [void]$names.Add($v) }
}

Say ''
if ($names.Count -eq 0) {
    Say '剪贴板里没找到警告名（形如 -Wxxxx）。'
    Say '下面是速查卡：gcc 到现在一共就骂过你这 17 种 ——'
    Say ''
    foreach ($s in $secs) {
        $t = $s.Title -replace '^###\s*', '' -replace '\*\*', ''
        Say ('  ' + $t + '   [' + ((NamesOf $s.Text) -join ' ') + ']')
        $d = @((Dash $s.Text) -split "`n")
        if ($d.Count -gt 0 -and $d[0].Trim() -ne '') { Say ('      ' + ($d[0] -replace '\*\*', '' -replace '[\u26A0\uFE0F]', '')) }
    }
    Say ''
    Say '--- 复制编译输出里那一行（带 [-Wxxxx] 的），再双击一次 ---'
} else {
    $hit = 0
    foreach ($name in $names) {
        $pat = [regex]::Escape($name) + '(?![A-Za-z0-9-])'
        $found = @($secs | Where-Object { $_.Text -match $pat })
        if ($found.Count -eq 0) {
            Say ('=' * 64)
            Say ('表里还没有「' + $name + '」')
            Say ('=' * 64)
            Say '  不管哪个警告，都先做这 4 步：'
            Say '    1. 只看最后方括号里的 -Wxxxx（那是名字，前面的英文不用读）'
            Say '    2. 看 ~~~^~~~ 箭头指的那一行'
            Say '    3. 看 note: 开头那行 —— 编译器常常直接把答案说了'
            Say '    4. 拿名字 Ctrl+F 搜 D:\cpp\警告翻译表.md'
            Say ''
        }
        foreach ($s in $found) {
            $hit++
            Say ('=' * 64)
            Say (' ' + ($s.Title -replace '^###\s*', '' -replace '\*\*', ''))
            Say ('=' * 64)
            $inCode = $false
            foreach ($ln in ($s.Text -split "`n")) {
                if ($ln.TrimStart().StartsWith('```')) { $inCode = -not $inCode; continue }
                if ($inCode) { if ($ln.Trim() -ne '') { Say ('    ' + ($ln -replace '\*\*', '' -replace '[\u26A0\uFE0F]', '')) } }
            }
            foreach ($b in @((Dash $s.Text) -split "`n")) {
                if ($b.Trim() -ne '') { Say ('  * ' + ($b -replace '\*\*', '' -replace '[\u26A0\uFE0F]', '')) }
            }
            Say ''
        }
    }
    if ($hit -eq 0) { Say '' }
}
Say '--- 表里没有的警告：把编译输出那一整行发给学长，补进表里下次就有了 ---'