# SecurityUtility
## 1 Introduction
This repo is mainly used to record some classical algorithms and their usage of security.  
Now the context mainly includes 2 parts:    
* Part 1, Already record:  
      PBKDF2(password-Based Key Derivation Function 2)  
* Part 2,To be record:  
      AES  
      RSA  
      ,,,  
## 2 How to compiling?
(1) The c program envrionment is necessary.
    You can download gcc/gcc from the website： https://gcc.gnu.org/ and then install it to your local computer.  
    After the gcc has been installed, you can open the terminal(Mac/Linux) or Windows(CMD), 
    enter "python --version" to check whether it has been added to your computer. Any questions happen, you can 
    ask the internet for help, the installing is not very difficult and there are many tutorials online.    
(2) Use "make" to build the project 
    The make envrionment will be installed when you installing gcc. 
    After successful installing, enter the rootpath in your terminal(Mac/Linux) or Windows(CMD), 
    then input "make" and click the "Enter" key on the keyboard.  the my.exe file will be build and added to the rootpath.
## 3 How to run the program?
     Enter your terminal(Mac/Linux) or Windows(CMD), and then input "./my.exe", the program will run and give the result to you.
## 4 What is the file structure? What's the usage of each file?
(1) makefile: to build the whole program and create corresponding executable file "my.exe", you can modify the file name to "my.elf" or other names.  
(2) main.c : the entry of the whole program.  
(3) test.c : different modules' test function will be added to this file, and this file provide one test() function to be called by main().  
(4) pbkdf2.c: realize the pbkdf2 algorithm with c code.  
(5) *.h : give interface to other c file to call some function , define some data structrue/MACRONs.  
## 5 How to contact the repo's owner? 
send e-mail: 1171213808@qq.com
## 6 How to download the code?
(1)If you has installed the git software: enter a terminal , input "git clone https://github.com/EricHaishen/SecurityUtility.git"..
(2)If you dont have the git environment buf you want to download, download it directly by click the link: https://github.com/EricHaishen/SecurityUtility/archive/refs/heads/main.zip
