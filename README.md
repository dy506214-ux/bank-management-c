# 🏦 Bank Account Management System in C

## 👩‍💻 Author
**Name:** Kashmiara Yadav  
**Roll No:** BC2024086  
**College:** Invertis University  
**Course:** BCA – 3rd Semester  

---

## 🎯 Aim of the Project
To develop a simple **Bank Account Management System** using the **C programming language** that allows users to manage multiple bank accounts efficiently.

---

## 📝 Features
✅ Create New Bank Account  
✅ Deposit Money  
✅ Withdraw Money  
✅ Check Balance  
✅ List All Accounts  
✅ Exit Program Safely  

---

## ⚙️ Tools Used
- **Language:** C  
- **IDE:** VS Code  
- **Compiler:** GCC (MinGW for Windows)  

---

## 📊 Working of Project
The system works through a menu-driven interface:  
1. User selects an option (1–6) from the main menu.  
2. Program performs the operation (Create, Deposit, Withdraw, etc.).  
3. Data is stored temporarily in the program (can be extended to file storage).  

---

## 💻 Sample Output
```
==== BANK ACCOUNT MANAGEMENT SYSTEM ====
1. Create New Account
2. Deposit Money
3. Withdraw Money
4. Check Balance
5. List All Accounts
6. Exit
Enter your choice: 1

Enter Account Number: 1001
Enter Name: Kashmiara
Enter Initial Deposit: 5000
Account Created Successfully!

---------------------------------------
Enter your choice: 2
Enter Account Number: 1001
Enter Amount to Deposit: 1500
Money Deposited Successfully!

---------------------------------------
Enter your choice: 4
Enter Account Number: 1001
Account Balance: ₹6500

---------------------------------------
Enter your choice: 6
Thank you for using Bank Account Management System!
```

---

## 📘 Result
The program successfully implements a **menu-driven bank account management system** with basic banking operations.

---

## 🔮 Future Scope
- Add file handling for permanent data storage  
- Add password protection for accounts  
- Create a graphical interface using C++ or Python  

---

## 📂 How to Run
1. Save the file as `bank.c`  
2. Open **VS Code Terminal**  
3. Compile using:  
   ```
   gcc bank.c -o bank
   ```  
4. Run the program:  
   ```
   ./bank
   ```
