# Clone

- ## Cloning to a specific folder  
```git clone <repo> <directory>```

- ## Cloning a specific branch/tag  
```git clone --branch <tag> <repo> <directory>```

- ## Shallow clone  
```git clone -depth=1 <repo> <directory>```   
Clone the repository located at <repo> and only clone the history of commits specified by the option depth=1. In this example a clone of <repo> is made and only the most recent commit is included in the new cloned Repo. Shallow cloning is most useful when working with repos that have an extensive commit history. An extensive commit history may cause scaling problems such as disk space usage limits and long wait times when cloning. A Shallow clone can help alleviate these scaling issues.

- ## Cloning bare repository  
```git clone --bare <repo> <directory>```  
Similar to git init --bare, when the -bare argument is passed to git clone, a copy of the remote repository will be made with an omitted working directory. This means that a repository will be set up with the history of the project that can be pushed and pulled from, but cannot be edited directly. In addition, no remote branches for the repo will be configured with the -bare repository. Like git init --bare, this is used to create a hosted repository that developers will not edit directly.
  
- ## Cloning bare repository  
```git clone --mirror <repo> <directory>```  
Passing the --mirror argument implicitly passes the --bare argument as well. This means the behavior of --bare is inherited by --mirror. Resulting in a bare repo with no editable working files. In addition, --mirror will clone all the extended refs of the remote repository, and maintain remote branch tracking configuration. You can then run git remote update on the mirror and it will overwrite all refs from the origin repo. Giving you exact 'mirrored' functionality.
