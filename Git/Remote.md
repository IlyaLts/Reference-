# Remote

The git remote command lets you create, view, and delete connections to other repositories. Remote connections are more like bookmarks rather than direct links into other repositories. Instead of providing real-time access to another repository, they serve as convenient names that can be used to reference a not-so-convenient URL.

- #### View all remote configurations  
```git remote``` or with URL ```git remote -v```

- #### Add a new remote configuaration  
```git remote add <name> <url>```

- #### Remove a remote configuration  
```git remote rm <name>```

- #### Rename a remote configuration  
```git remote rename <old-name> <new-name>```

- #### Show detailed output on the configuration of a remote  
```git remote show <name>```
