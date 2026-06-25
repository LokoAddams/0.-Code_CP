$f = $args[0]
g++ -std=c++17 -O2 "$f\$f.cpp" -o "$f\$f.exe"
if (!$?) { exit }

cd $f
ls *.in -ea 0 | % { 
  Write-Host "--- $($_.Name) ---" -f Cyan
  cat $_ | & ".\$f.exe" | tee "$($_.BaseName).out" 
}
cd ..