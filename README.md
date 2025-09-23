# Data Structure Learning Log

This project is used to document the learning journey of data structures. I will be documenting my notes and coding exercises here.

## Outline

- Git
- C++
- Data Structure

## Git

This section will include some notes about usage of Git and GitHub.

### Initialize Local Repository.

**1. Make a new directory named `<project-name>` and change directory**

Open the terminal, and input command below:

```Bash
mkdir <project-name>
cd <project-name>
```

**2. Initialize local git repository**

Use `init` to initialize directory to a Git repository.

```Bash
git init
```

**3. Create any file in the `<project-name>` directory**

Generate any file in project directory.

**4. Use git command to stage and commit changes**

Use `add` to stage the change for the files.
Use `commit` to commit staged changes.

```Bash
git add .   #stage all files
git add <file-name>   #stage specific file
git commit -m "<any-comment>"   #commit the already staged changes with a comment.
```

### Make connection between computer and GitHub

**1. Check if an SSH key already exists on the computer**

Open the terminal (MacOS, Linux) or Git Bash (Windows), and input command below:

```Bash
ls -al ~/.ssh
```

If there are some file like `id_ed25519.pub`, it means the computer already has a public key. Skip to step **3.**.

If the output is `No such file or directory`, proceed to step **2.** to create a new key.

**2. Create a new SSH key**

Enter the following command in the terminal to generate a new key pair. Ed25519 algorithm is used here.

```Bash
ssh-keygen -t ed25519 -C "<GitHub-mail>"
```

Once the command is executed, the system will prompt you to specify a location to save the key. Press Enter to accept the default path.

The system will then ask you to enter a passphrase. This serves as an extra layer of protection and is recommended. Each time the key is used, the passphrase will be required. You may choose to set one, or press Enter to leave it empty.

Once completed, two files will be generated in your `.ssh` directory:
- `id_ed25519`: This is your private key. Do not share this file with anyone!
- `id_ed25519.pub`: This is your public key. We will copy the contents of this file to GitHub.

**3. Add public key to your GitHub**

Check the contents of your public key by the following command in terminal or Git Bash:

```Bash
cat ~/.ssh/id_ed25519.pub
```

_Copy_ the contents in `id_ed25519.pub`.

Login to GitHub > Click your profile picture > `Settings` > Click `SSH and GPG keys` in left-hand menu > Click `New SSH key` > Type `<device-name>` in **Title** field > Paste public key contents in **Key** field > Click `Add SSH key`

**4. Veify the SSH connection**

Enter the command below to test:

```Bash
ssh -T git@github.com
```

- The first time you connect, the system will ask if you trust the connection. Type `yes` and press Enter.
- If you previously set a passphrase for your key, you’ll be prompted to enter it now.
- If you see a message like `“Hi <your-username>! You've successfully authenticated...”`, it means your SSH key has been set up successfully!

### Make connection between local repo and GitHub repo

**1. Create a new empty repository on GitHub**

- Log in to GitHub and click the + icon in the top-right corner.
- Select `New repository` from the dropdown menu.
- Enter your repository name `<repository-name>`.
- Do not select any options (e.g., Add a README file), since you already have the files locally.
- Click `Create repository` to finish.

**2. Connect to local repository**

Use the command below in terminal to link local and remote repos:

```Bash
git remote add origin git@github.com:<GitHub-user-name>/<GitHub-repo-name>.git
```

**3. Push local contents to GitHub**

Use `git push` command to upload local contents to GitHub repo.
>