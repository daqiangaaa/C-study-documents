@echo off
chcp 936 >nul
title 题解一键上传
cd /d D:\cpp

echo ==============================================
echo             题 解 一 键 上 传
echo ==============================================
echo.

set "GITP="
set "RURL="
for /f "delims=" %%u in ('git remote get-url origin 2^>nul') do set "RURL=%%u"
if "%RURL%"=="" (
  echo [错误] 没有配置 origin 远程仓库, 请先双击 "换成Gitee" 配一个。
  pause
  exit /b 1
)

echo %RURL% | findstr /i "github.com" >nul
if errorlevel 1 goto noproxy

set "PEN="
set "PSRV="
for /f "tokens=2,*" %%a in ('reg query "HKCU\Software\Microsoft\Windows\CurrentVersion\Internet Settings" /v ProxyEnable 2^>nul ^| findstr /i "ProxyEnable"') do set "PEN=%%b"
for /f "tokens=2,*" %%a in ('reg query "HKCU\Software\Microsoft\Windows\CurrentVersion\Internet Settings" /v ProxyServer 2^>nul ^| findstr /i "ProxyServer"') do set "PSRV=%%b"
if /i "%PEN%"=="0x1" if not "%PSRV%"=="" set "GITP=-c http.proxy=http://%PSRV%"
:noproxy
if "%GITP%"=="" (echo [上传目标] %RURL%  ^(直连^)) else (echo [上传目标] %RURL%  ^(经加速器 %PSRV%^))
echo.

echo [1/4] 归档当前题解
echo.

set "SRC="
for /f "usebackq delims=" %%F in (`powershell -NoProfile -Command "$all=@(); $all += Get-ChildItem 'D:\cpp' -Recurse -Include *.c,*.cpp -File -ErrorAction SilentlyContinue; $all += Get-ChildItem 'E:\比赛\*' -Include *.c,*.cpp -File -ErrorAction SilentlyContinue; $f=$null; foreach($x in $all){ if($x.FullName -like '*\solutions\*' -or $x.FullName -like '*\obj\*' -or $x.FullName -like '*\bin\*' -or $x.FullName -like '*\.git\*' -or $x.FullName -like '*\_recovered\*' -or $x.FullName -like '*\.npm-cache\*'){continue}; if($f -eq $null -or $x.LastWriteTime -gt $f.LastWriteTime){$f=$x} }; if($f){$f.FullName}"`) do set "SRC=%%F"

if "%SRC%"=="" goto nosrc

for %%A in ("%SRC%") do set "SMT=%%~tA"
for %%A in ("%SRC%") do set "SNM=%%~nxA"
for %%A in ("%SRC%") do set "SEX=%%~xA"
echo       自动找到最近改动的源文件:
echo           %SRC%
echo           修改时间 %SMT%   文件 %SNM%
echo.
set "HEAD=%SRC:~0,7%"
if /i not "%HEAD%"=="D:\cpp\" echo       [提醒] 这个文件不在 D:\cpp 里, 建议写到工程 D:\cpp\比赛3\main.c 或 D:\cpp\比赛4\main.cpp
if /i not "%HEAD%"=="D:\cpp\" echo              在工程里按 F9 才能编译出程序 ^(E:\比赛 是中文路径, 链接会失败^)
echo.

set "NAME="
set /p "NAME=      题目名 (直接回车 = 不归档): "
if "%NAME%"=="" goto skiparc

set "DEST=D:\cpp\solutions\%NAME%%SEX%"

if not exist "%DEST%" goto docopy

echo.
echo       [注意] solutions\%NAME%%SEX% 已经存在了!
set "ANS="
set /p "ANS=      覆盖它吗? 输入 Y 覆盖, 直接回车跳过: "
if /i not "%ANS%"=="Y" goto skiparc
echo.

:docopy
copy /y "%SRC%" "%DEST%" >nul
if errorlevel 1 (echo       [错误] 复制失败) else (echo       已归档  -^>  solutions\%NAME%%SEX%)
echo.
goto commit

:skiparc
echo       这次不归档, 直接上传现有改动。
echo.
goto commit

:nosrc
echo       [警告] 没找到任何 .c / .cpp 文件, 这次不归档。
echo.

:commit
echo [2/4] 记录改动
set "MSG="
set /p "MSG=      这次干了啥 (回车 = 自动写日期): "
if "%MSG%"=="" set "MSG=更新 %date%"
git add -A
git commit -m "%MSG%"

echo.
echo [3/4] 上传到 Gitee...
git %GITP% push -u origin main
if not errorlevel 1 goto ghsync

echo.
echo       第一次没成, 合并远程已有内容后再传一次...
git %GITP% pull origin main --allow-unrelated-histories --no-rebase --no-edit
git %GITP% push -u origin main
if not errorlevel 1 goto ghsync

echo.
echo ==============================================
echo   还是不行, 按顺序检查:
echo   1. 账号密码/令牌 输对了吗?
echo   2. 远程仓库地址对不对?  双击 "换成Gitee.bat" 重设
echo   3. 若是 GitHub: 加速器开了吗? GitHub 那项勾了吗?
echo ==============================================
pause
exit /b 1

:ghsync
echo.
echo [4/4] 同步到 GitHub...
git remote get-url github >nul 2>&1
if errorlevel 1 goto nogh

set "GPEN="
set "GPSRV="
for /f "tokens=2,*" %%a in ('reg query "HKCU\Software\Microsoft\Windows\CurrentVersion\Internet Settings" /v ProxyEnable 2^>nul ^| findstr /i "ProxyEnable"') do set "GPEN=%%b"
for /f "tokens=2,*" %%a in ('reg query "HKCU\Software\Microsoft\Windows\CurrentVersion\Internet Settings" /v ProxyServer 2^>nul ^| findstr /i "ProxyServer"') do set "GPSRV=%%b"
set "GGITP="
if /i "%GPEN%"=="0x1" if not "%GPSRV%"=="" set "GGITP=-c http.proxy=http://%GPSRV%"

git %GGITP% push github main
if not errorlevel 1 goto ghok

echo       GitHub 第一次没成, 合并后再试一次...
git %GGITP% pull github main --allow-unrelated-histories --no-rebase --no-edit -X ours
git %GGITP% push github main
if not errorlevel 1 goto ghok

echo.
echo       [提醒] Gitee 已经上传好了, 这次 GitHub 没同步上。
echo              想补同步: 双击桌面的 "推送到GitHub"
goto ok

:ghok
echo       GitHub 已同步。
goto ok

:nogh
echo       (没有配置 github 远程, 跳过)
goto ok

:ok
echo.
echo ==============================================
echo   全部完成!   %RURL%
echo ==============================================
pause
exit /b 0
