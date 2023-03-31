# Blame.md

- #### Show what revision and author last modified each line of a file  
```git blame README.MD```

- #### The -e option shows the authors email address instead of username.  
```git blame -e README.md```

- #### The -L option will restrict the output to the requested line range. Here we have restricted the output to lines 1 through 5.  
```git blame -L 1,5 README.md```  

- #### The -M option detects moved or copied lines within in the same file. This will report the original author of the lines instead of the last author that moved or copied the lines.  
```git blame -M README.md```

- #### The -C option detects lines that were moved or copied from other files. This will report the original author of the lines instead of the last author that moved or copied the lines.  
```git blame -C README.md```
