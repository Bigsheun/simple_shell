@echo off

if 0%1%==01 goto perfom_task1
if 0%1%==02 goto perfom_task2
if 0%1%==03 goto perfom_task3
if 0%1%==04 goto perfom_task4
if 0%1%==05 goto perfom_task5
if 0%1%==06 goto perfom_task6
if 0%1%==07 goto perfom_task7
if 0%1%==08 goto perfom_task8
if 0%1%==09 goto perfom_task9
if 0%1%==010 goto perfom_task10
if 0%1%==011 goto perfom_task11
if 0%1%==012 goto perfom_task12
if 0%1%==013 goto perfom_task13
if 0%1%==014 goto perfom_task14
if 0%1%==015 goto perfom_task15

echo Usage:  MakeTarget index 
echo where index = 1 - 15

echo 1. make getppid.o 
echo 2. make getline.o 
echo 3. make fork.o 
echo 4. make outputs.o 
echo 5. make env.o 
echo 6. make env2.o 
echo 7. make inbuilt_cmd.o 
echo 8. make inbuilt_cmd2.o 
echo 9. make string_utils1.o 
echo 10. make string_utils2.o 
echo 11. make arg_parse.o 
echo 12. make errors.o 
echo 13. make external_cmd.o 
echo 14. make paths.o 
echo 15. make simple_shell.o 

goto done_all

:perfom_task1
cls
make getppid.o
goto done_all

:perfom_task2
cls
make getline.o
goto done_all

:perfom_task3
cls
make fork.o
goto done_all

:perfom_task4
cls
make outputs.o
goto done_all

:perfom_task5
cls
make env.o
goto done_all

:perfom_task6
cls
make env2.o
goto done_all

:perfom_task7
cls
make inbuilt_cmd.o
goto done_all

:perfom_task8
cls
make inbuilt_cmd2.o
goto done_all

:perfom_task9
cls
make string_utils1.o
goto done_all

:perfom_task10
cls
make string_utils2.o
goto done_all

:perfom_task11
cls
make arg_parse.o
goto done_all

:perfom_task12
cls
make errors.o
goto done_all

:perfom_task13
cls
make external_cmd.o
goto done_all

:perfom_task14
cls
make paths.o
goto done_all

:perfom_task15
cls
make simple_shell.o
goto done_all


:done_all
echo done
