# Description
Simulate the linux command `sort` and `uniq`.      
# Synopsis       
**mysort usage:**      
mysort \[-ih\] [-o output\_file] input\_file          
**Parameter:**         
**-i**: Case insensitive sorting.Default is case sensitive sorting.     
**-o**: Specify the output file.Default is **sorted.txt**.      
**-h**: See help      
**P.S.** *input\_file* is the file that you want to sort.         

------
**myuniq usage:**        
myuniq \[-h\] \[-o output\_file\] input\_file        
**Parameter:**         
**-o**: Specify the output file.Default is **uniq.txt**.        
**-h**: See help.      
**P.S.** *intput\_file* is the file that you want to sort.        
# How to run the program?
Run mysort as        
```
$ make mysort      
$ ./mysort [-ih] [-o output_file] input_file     
```          
**Example:**         
```
$ make mysort      
$ ./mysort sort_example.txt       
```      

-----------
Run myuniq as       
```
$ make myuniq      
$ ./myuniq [-o output_file] [-h] input_file       
```
**Example:**          
```
$ make myuniq         
$ ./myuniq uniq_example.txt        
```
