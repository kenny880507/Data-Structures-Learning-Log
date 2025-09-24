# Data Structure Learning Log

This project is used to document the learning journey of data structures. I will be documenting my notes and coding exercises here.


## Outline

- Data Structure
- C++
- Git
- Helpful Links

## Data Structure

This section will introduce common containers in data structure. The content covers the definition of each container and the four fundamental operations: access, search, insert, and delete.

### Cheat Sheet

reference: [Big-O Cheat Sheet](https://www.bigocheatsheet.com/)

#### Big-O Complexity Chart

![Big-O Complexity Chart](documents/images/Data%20Structure/Big-O%20Complexity%20Chart.png)

#### Common Data Structure Operations

![Big-O Complexity Chart](documents/images/Data%20Structure/Common%20Data%20Structure%20Operations.png)

#### Array Sorting Algorithms

![Big-O Complexity Chart](documents/images/Data%20Structure/Array%20Sorting%20Algorithms.png)

## C++

This section records the C++ syntax used in my code and demonstrates how to implement different data structures using C++.

The execution strategy is below:

1. The container holds only objects and iterators, without defining any member functions.
2. The four fundamental operations of data structures—access, search, insert, and delete—are implemented using template functions.
3. These functions take iterators as parameters instead of the container itself, allowing operations to be performed through the iterator interface.

### Syntax

#### Class

#### function

#### Overload

#### Template

#### Iterator

#### Tag Type

Tag type is basically a empty struct. Tag types are used as a mechanism to distinguish between overloaded functions. For example, two tag type is defined:

```C++
struct type1_tag{};
struct type2_tag{};
```

The tag type is passed as a parameter to the overloaded function, enabling different behaviors depending on the tag:

```C++
template<typename Iterator>
typename Iterator::value_type do_something(Iterator it, type1_tag){
    ...
}
template<typename Iterator>
typename Iterator::value_type do_something(Iterator it, type2_tag){
    ...
}
```
The reason for using this syntax is that different iterators support different operations—not all iterators can move forward, backward, or perform random access.

### Implement of Data Structure

### Data Structure vs. C++ STL Container

| Data Structure | C++ STL Container | Notes |
| :--- | :--- | :--- |
| **Array** | `std::array`, `std::vector` | `std::array` has a fixed size at compile time, while `std::vector` can be resized dynamically. |
| **Linked List** | `std::list`, `std::forward_list` | `std::list` is a doubly linked list, `std::forward_list` is a singly linked list. |
| **Tree** | `std::set`, `std::map`, `std::multiset`, `std::multimap` | These are typically implemented using **balanced binary search trees** (e.g., Red-Black Trees) to keep data sorted. |
| **Heap** | `std::priority_queue` | The underlying data structure is a heap (by default, a max-heap), providing efficient access to the largest element. |
| **Queue** | `std::queue` | A First-In, First-Out (FIFO) container. |
| **Stack** | `std::stack` | A Last-In, First-Out (LIFO) container. |
| **Graph** | **No direct equivalent** | Often simulated using an **adjacency matrix** (`std::vector<std::vector<int>>`) or an **adjacency list** (`std::vector<std::list<int>>`). |
| **Hash Table** | `std::unordered_set`, `std::unordered_map` | Provides average O(1) time complexity for lookups, but the data is not sorted. |

## Git

This section will include some notes about usage of Git and GitHub.

### Initialize Local Repository.

#### 1. Make a new directory named `<project-name>` and change directory

Open the terminal, and input command below:

```Bash
mkdir <project-name>
cd <project-name>
```

#### 2. Initialize local git repository

Use `init` to initialize directory to a Git repository.

```Bash
git init
```

#### 3. Create any file in the `<project-name>` directory

Generate any file in project directory.

#### 4. Use git command to stage and commit changes

Use `add` to stage the change for the files.
Use `commit` to commit staged changes.

```Bash
git add .   #stage all files
git add <file-name>   #stage specific file
git commit -m "<any-comment>"   #commit the already staged changes with a comment.
```

### Make connection between computer and GitHub

#### 1. Check if an SSH key already exists on the computer

Open the terminal (MacOS, Linux) or Git Bash (Windows), and input command below:

```Bash
ls -al ~/.ssh
```

If there are some file like `id_ed25519.pub`, it means the computer already has a public key. Skip to `step 3.`.

If the output is `No such file or directory`, proceed to `step 2.` to create a new key.

#### 2. Create a new SSH key

Enter the following command in the terminal to generate a new key pair. Ed25519 algorithm is used here.

```Bash
ssh-keygen -t ed25519 -C "<GitHub-mail>"
```

Once the command is executed, the system will prompt you to specify a location to save the key. Press Enter to accept the default path.

The system will then ask you to enter a passphrase. This serves as an extra layer of protection and is recommended. Each time the key is used, the passphrase will be required. You may choose to set one, or press Enter to leave it empty.

Once completed, two files will be generated in your `.ssh` directory:
- `id_ed25519`: This is your private key. Do not share this file with anyone!
- `id_ed25519.pub`: This is your public key. We will copy the contents of this file to GitHub.

#### 3. Add public key to your GitHub

Check the contents of your public key by the following command in terminal or Git Bash:

```Bash
cat ~/.ssh/id_ed25519.pub
```

_Copy_ the contents in `id_ed25519.pub`.

Login to GitHub > Click your profile picture > `Settings` > Click `SSH and GPG keys` in left-hand menu > Click `New SSH key` > Type `<device-name>` in **Title** field > Paste public key contents in **Key** field > Click `Add SSH key`

#### 4. Veify the SSH connection

Enter the command below to test:

```Bash
ssh -T git@github.com
```

- The first time you connect, the system will ask if you trust the connection. Type `yes` and press Enter.
- If you previously set a passphrase for your key, you’ll be prompted to enter it now.
- If you see a message like `“Hi <your-username>! You've successfully authenticated...”`, it means your SSH key has been set up successfully!

### Make connection between local repo and GitHub repo

#### 1. Create a new empty repository on GitHub

- Log in to GitHub and click the + icon in the top-right corner.
- Select `New repository` from the dropdown menu.
- Enter your repository name `<repository-name>`.
- Do not select any options (e.g., Add a README file), since you already have the files locally.
- Click `Create repository` to finish.

#### 2. Connect to local repository

Use the command below in terminal to link local and remote repos:

```Bash
git remote add origin git@github.com:<GitHub-user-name>/<GitHub-repo-name>.git
```

#### 3. Push local contents to GitHub

Use `git push` command to upload local contents to GitHub repo.
>- The main branch might be `main` or `master`. Use `git branch` to check.
>- For first push, a `-u origin main` parameter must be added.

```Bash
git push -u origin main
```

### Common Git Commands

~~`git pull`: download the newest changes to local repo and merge to loacal branch. Equivalent to `git fetch` + `git merge`.~~
>Barely using `git pull` is not recommended. Use `git pull --rebase` or `git fetch` + `git rebase` instead.

`git fetch`: download changes from the remote repository.

`git rebase`: moves your local commits to the top of the remote commits. This keeps your commit history clean and linear, without unnecessary merge commits.
>Never use `rebase` on public branches! If you perform a `rebase` on a public branch that others are working on—such as main—you’ll rewrite the commit history of that branch. This can cause other developers’ local histories to diverge from the remote history, leading to major confusion and conflicts.

`git pull --rebase`: equivalent to `git fetch` + `git rebase`.

`git checkout <branch-name>`: change to `<branch-name>` branch.

`git checkout -b <new-branch>`: create a new branch `<new-branch>` and change branch to `<new-branch>`.

`git push -u origin <new-branch>`: `-u` is used for pushing new branch. Git will set up tracking information for this branch on the remote.
>- Git uses origin as a default alias pointing to the remote repo.
>- If the branch already exists on the remote, a simple `git push` is enough.

## Helpful Links

[Big-O Cheat Sheet](https://www.bigocheatsheet.com/)