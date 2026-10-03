@echo off
chcp 936 >nul
title gcc ¾¯¸æ·­ÒëÆ÷
set "PS=powershell"
where pwsh >nul 2>nul && set "PS=pwsh"
%PS% -NoProfile -ExecutionPolicy Bypass -File "%~dp0²é¾¯¸æ.ps1" %*
echo.
pause