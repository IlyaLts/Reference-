# Tag

Annotated tags are meant for release while lightweight tags are meant for private or temporary object labels.

- #### Create a lightweight tag  
```git tag <tagname>```

- #### Create a annotated tag  
```git tag -a v1.4 -m "my version 1.4"```

- #### List tags  
```git tag```

- #### List specific tags  
```git tag -l *-rc*```

- #### Tag old commit  
```git tag -a v1.2 <SHA hash>```

- #### Retag/Replace old tag  
```git tag -a -f v1.4 <SHA hash>```

- #### Delete tag  
```git tag -d v1```
