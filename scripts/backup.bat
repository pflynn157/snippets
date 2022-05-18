@echo off

echo "Beginning backup..."

robocopy C:\Users\patrick\Archive D:\laptop\Archive /MIR /FFT /R:3 /W:10 /Z /NP /NDL
robocopy C:\Users\patrick\Desktop D:\laptop\Desktop /MIR /FFT /R:3 /W:10 /Z /NP /NDL
robocopy C:\Users\patrick\Documents D:\laptop\Documents /MIR /FFT /R:3 /W:10 /Z /NP /NDL
robocopy C:\Users\patrick\Downloads D:\laptop\Downloads /MIR /FFT /R:3 /W:10 /Z /NP /NDL
robocopy "C:\Users\patrick\Operating Systems" "D:\laptop\Operating Systems" /MIR /FFT /R:3 /W:10 /Z /NP /NDL
robocopy C:\Users\patrick\Music D:\laptop\Music /MIR /FFT /R:3 /W:10 /Z /NP /NDL
robocopy C:\Users\patrick\Pictures D:\laptop\Pictures /MIR /FFT /R:3 /W:10 /Z /NP /NDL
robocopy C:\Users\patrick\website D:\laptop\website /MIR /FFT /R:3 /W:10 /Z /NP /NDL

echo "Done"
pause

