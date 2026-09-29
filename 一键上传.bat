@echo off
cd /d D:\cpp

echo ==========================================
echo    题解  一键归档 + 上传
echo ==========================================
echo.

echo [1/3] 归档当前题解
set NAME=
set /p NAME=  题目名 (例如 P5705_数字反转, 直接回车=跳过): 
if not "%NAME%"=="" (
    if not exist "D:\cpp\solutions" mkdir "D:\cpp\solutions"
    copy /y "D:\cpp\比赛3\main.c" "D:\cpp\solutions\%NAME%.c" >nul
    echo        已归档到 D:\cpp\solutions\%NAME%.c
) else (
    echo        跳过归档
)
echo.

echo [2/3] 提交到本地...
set MSG=
set /p MSG=  本次说明 (直接回车=用日期): 
if "%MSG%"=="" set MSG=更新 %date%
git add -A
git commit -m "%MSG%"
echo.

echo [3/3] 上传到 GitHub...
git push -u origin main
if errorlevel 1 (
    echo.
    echo        正在合并远程已有内容后再传一次...
    git pull origin main --allow-unrelated-histories --no-rebase --no-edit
    git push -u origin main
)
echo.
echo ==========================================
echo    完成! 按任意键关闭窗口
echo ==========================================
pause >nul