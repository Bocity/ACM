# Atom
***
## Git push failed
Enter your folder and execute this command

    git remote set-url origin git@github.com:your_username/your_project.git
## Anyway to change UI/tab/tree view font size?
I found a wonderful answer by Google

https://github.com/atom/atom/issues/11905#issuecomment-224865625
![](http://p1.bpimg.com/567571/3453b41c7ece05d1.gif)

You can do it by editing two files:

    # init.coffee
    UIFontSize = 12
    atom.commands.add 'atom-workspace',
      'ui:increase-font-size': ->
        UIFontSize += 1
        document.documentElement.style.fontSize = UIFontSize + 'px'
      'ui:decrease-font-size': ->
        UIFontSize -= 1
        document.documentElement.style.fontSize = UIFontSize + 'px'


    # keymap.cson
    'atom-workspace':
      'ctrl-+': 'ui:increase-font-size'
      'ctrl--': 'ui:decrease-font-size'
## How to compile and run a c++ file like and IDE?
  I found this way to solve it;

  1. You should install a package

  https://atom.io/packages/atom-shell-commands

  By this command to install

      apm install atom-shell-commands
Be sure you had already installed <a href=https://nodejs.org/en/>Nodejs</a>


  2. Edit  config file (File->Open Your Config, or ~/.atom/config.cson)
 
          "atom-shell-commands":
          commands: [
            {
              name: "compile"
              command: "g++"
              arguments: [
                "{FileName}"
                "-o"
                "{FileNameNoExt}.exe"
              ]
              options:
                cwd: "{FileDir}"
                keymap: "ctrl-2"
                save: true
              }
              {
              name: "run"
              command: "cmd"
              arguments: [
                "/C"
                "start"
                "C:/Users/Administrator/.atom/launch.cmd"
                "{FileNameNoExt}"
              ]
              options:
                cwd: "{FileDir}"
                keymap: "ctrl-1"
                save: true
              }
              ]


Be sure that you had already added g++ to Path

you can control the shortcuts by modifying keymap

launch.cmd:

    @echo off
    %1
    echo.
    pause
    exit

![](http://i1.piimg.com/567571/7f1dc5968cd4cff2.jpg)
<a href=https://atom.io/packages/atom-shell-commands>More information</a>



# hexo
***
## error deployer not found:github
    npm install hexo-deployer-git --save

## can't open localhost:4000
    uninstall 福昕阅读器 or hexo s -p 5000

# GitHub
***
## github for windows login failed
    git config --global user.email yourmail
    git config --global user.name yourname
## install

add a hosts record

     54.231.98.184 github-com.s3.amazonaws.com
