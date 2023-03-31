# Rm

- #### Remove a file from the staged area  
```git rm <filepath>``` or force remove ```git rm -f <filepath>```

- #### Remove a file (dry run)  
```git rm -n <filepath>``` or ```git rm --dry-run <filepath>```  
It will output which files it would have removed.

- #### Remove a directory  
```git rm -r <dirpath>```
It will remove a target directory and all the contents of that directory.

- #### Remove from the staging index  
```git rm --cached <filepath>```
