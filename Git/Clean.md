# Clean

- #### Clean untracked files  
```git clean```

- #### Dry clean  
```git clean -n```  
The -n option will perform a “dry run” of git clean. This will show you which files are going to be removed without actually removing them.

- #### Force clean unracked files
```git clean -f``` or dry run ```git clean -fn```  
The force option initiates the actual deletion of untracked files from the current directory.

- #### Force clean untracked files/directories  
```git clean -d``` or dry run ```git clean -dn```  
The -d option tells git clean that you also want to remove any untracked directories, by default it will ignore directories.

- #### Force removal of ignored files  
```git clean -xf```

- #### Clean with interactive mode  
```git clean -i``` or ```git clean -di```  
