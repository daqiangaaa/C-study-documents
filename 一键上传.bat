@echo off
chcp 936 >nul
title 题解一键上传
cd /d D:\cpp

echo ==============================================
echo             题 解 一 键 上 传
echo ==============================================

set "GITP="
set "RURL="
for /f "delims=" %%u in ('git remote get-url origin 2^>nul') do set "RURL=%%u"
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
echo [1/3] 归档当前题解
set "NAME="
set /p "NAME=      题目名(不想归档就直接回车): "
if not "%NAME%"=="" (
  copy /y "D:\cpp\比赛3\main.c" "D:\cpp\solutions\%NAME%.c" >nul
  echo       已存到 solutions\%NAME%.c
) else (
  echo       跳过
  )

echo.
echo [2/3] 记录改动
set "MSG="
set /p "MSG=      这次干了啥(回车=自动写日期): "
if "%MSG%"=="" set "MSG=更新 %date%"
git add -A
git commit -m "%MSG%"

echo.
echo [3/3] 上传...
git %GITP% push -u origin main
if not errorlevel 1 goto ok

echo.
echo       第一次没成, 合并远程已有内容后再传一次...
git %GITP% pull origin main --allow-unrelated-histories --no-rebase --no-edit
git %GITP% push -u origin main
if not errorlevel 1 goto ok

echo.
echo ==============================================
echo   还是不行, 按顺序检查:
echo   1. 账号密码/令牌 输对了吗?
echo   2. 远程仓库地址对不对?  双击 "换成Gitee.bat" 重设
echo   3. 若是 GitHub: 加速器开了吗? GitHub 那项勾了吗?
echo ==============================================
pause >nul
exit /b 1

:ok
echo.
echo ==============================================
echo   上传成功!   %RURL%
echo ==============================================
pause >nul
exit /b 0