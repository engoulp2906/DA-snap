# DA-snap

**DESCRIPTION: **
• This C++ program is a simple login and authentication system that allows users to create accounts, login, list all accounts, search for accounts by name, modify account details, change passwords, and delete accounts. • The program consists of several classes (login_system, CreateAcc, LoginPage, ListAccount, SearchAccount) that handle different functionalities of the system. 
• Users can create accounts by providing a unique username, contact details, email address, and date of birth. Password creation is also included with basic validation. 
• Authentication is done through a login page where users enter their username and password. The system verifies the credentials against the stored data. 
• Users can view their account details, modify account information, change passwords, and delete their accounts. 
• The program uses file handling to store user data persistently.



**UNIQUE FEATURES: **
1. Password Masking: 
When users enter their password, it's masked with asterisks for privacy and security. This feature enhances the confidentiality of user credentials. 
2. Account Creation with Unique Details: 
When creating an account, the system checks if the entered username, phone number, and email address are unique. If not, it prompts the user to enter different details, ensuring data integrity. 
3. Regex Validation for Email and Phone: Regular expressions are used to validate email addresses and phone numbers entered during account creation. This ensures that the provided data follows the correct format. 
4. Delayed Output for Visual Appeal: 
Throughout the application, delays are introduced between actions, providing a smoother user experience. For example, when verifying user data during login or waiting for actions to complete, a delay is implemented. This adds a sense of interaction and responsiveness to the application. 
5. Secure Password Change: 
Users can change their passwords securely by entering their old password and then confirming the new one. This prevents unauthorized password changes and ensures user account security. 6. Account Deletion Confirmation: When a user requests to delete their account, the application prompts for confirmation to prevent accidental deletions.



**Banking Portal**

1. Initialise Accounts:
This function initialises a set of predefined bank accounts with default values.
Each account is assigned an account number, account holder name, balance, and credit score.
It's intended to set up some sample data for testing and demonstration purposes.

2. Create Account:
Allows users to create a new bank account.
Users input details such as account number, account holder name, account history, payment history, debt-to-income ratio, and other factors.
The entered details are used to create a new account with zero balance and a provided credit score.

3. Login:
Authenticates users by prompting them for a 	username and password.
Currently, it uses a hardcoded username ("user") and password (“password").
A simple boolean value indicates whether the login attempt was successful.

4. Display Menu:
Shows the main menu options to the user.
Provides a list of available actions such as creating an account, checking balance, depositing money, transferring money, applying for a loan, etc.

5. Check Balance:
Allows users to check the balance of their bank account.
Prompts the user to input their account number and then retrieves and displays the account's current balance.

6. Deposit Money:
Enables users to deposit money into their bank accounts.
Users provide their account number and the amount they wish to deposit.
The deposited amount is added to the account's balance.

7. Transfer Money:
Facilitates the transfer of money between two accounts.
Users specify the sender's and receiver's account numbers along with the transfer amount.
The transfer is executed if the sender has sufficient balance, and both accounts are updated accordingly.

8. Apply for Loan:
Allows users to apply for a loan.
Users input their account number and the desired loan amount.
Loan approval is based on the user's credit score, with a simple check to ensure it meets a minimum threshold (650 in this case).

9. Check Credit Score:
Lets users check their credit score associated with their bank account.
Users input their account number, and the system retrieves and displays the corresponding credit score.

10. Purchase Insurance:
Enables users to purchase insurance for their bank account.
Users provide their account number, policy number, coverage amount, and premium.
Once purchased, the insurance details are stored with the account.

11. Check Insurance Policy:
Allows users to check the details of their insurance policy.
Users input their account number, and the system retrieves and displays the associated insurance policy details.

12. Make Insurance Claim:
Enables users to make an insurance claim.
Users input their account number, and if an insurance policy is associated with the account and no previous claims have been made, a claim is processed.
