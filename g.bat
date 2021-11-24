@ECHO OFF

echo last updated at...> update.txt
echo %date% %time%>> update.txt

git pull
git add .
git commit -m "regular update"
git push