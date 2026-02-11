@echo off
setlocal enabledelayedexpansion

:: 1. Folder list
set FOLDERS=android

:: Set user config
git config user.name "Dain"
git config user.email "dain@example.com"

:: Save current branch
for /f "tokens=*" %%i in ('git rev-parse --abbrev-ref HEAD') do set ORIGINAL_BRANCH=%%i

for %%F in (%FOLDERS%) do (
    echo ============================================
    echo Current Task: %%F
    
    :: [1] Create and switch branch
    git checkout -B %%F --quiet
    
    :: [2] Clean workspace (delete everything except .git and scripts)
    echo Cleaning workspace...
    for /d %%p in (*) do (
        if /i not "%%p"==".git" rd /s /q "%%p"
    )
    for %%f in (*) do (
        if /i not "%%f"=="deploy_sca.bat" if /i not "%%f"=="deploy.ps1" del /q "%%f"
    )

    :: [3] Copy files from PARENT directory's temporary_folder
    echo Copying files from ..\temporary_folder\%%F
    if not exist "sca\%%F" mkdir "sca\%%F"
    
    :: ..\ 를 사용하여 상위 폴더의 temporary_folder를 참조합니다.
    if exist "..\temporary_folder\%%F" (
        xcopy /e /i /y "..\temporary_folder\%%F" "sca\%%F" > nul
        
        :: [4] Commit and Push
        echo Committing and Pushing...
        git add .
        git commit -m "Add %%F source in sca/ directory" --no-edit
        git push origin %%F --force --progress
        
        echo SUCCESS: %%F completed.
    ) else (
        echo WARNING: Source not found at ..\temporary_folder\%%F
    )

    :: Back to original state for next loop
    git checkout -f %ORIGINAL_BRANCH% --quiet
)

echo ============================================
echo All tasks completed!
pause