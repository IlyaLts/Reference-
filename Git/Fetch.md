# Fetch

The git fetch command downloads commits, files, and refs from a remote repository into your local repo. Fetching is what you do when you want to see what everybody else has been working on. It’s similar to svn update in that it lets you see how the central history has progressed, but it doesn’t force you to actually merge the changes into your repository. Git isolates fetched content from existing local content; it has absolutely no effect on your local development work. Fetched content has to be explicitly checked out using the git checkout command. This makes fetching a safe way to review commits before integrating them with your local repository.

- #### Fetch default remote  
```git fetch```

- #### Fetch all of the branches from the repository  
```git fetch <remote>```

- #### Fetch the specified branch  
```git fetch <remote> <branch>```

- #### Fetch all registered remotes and their branches  
```git fetch -all```

- #### Fetch a specific remote branch from the repository  
```git fetch <coworkers_repo> <coworkers>/<feature_branch>```
