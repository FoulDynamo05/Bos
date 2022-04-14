import java.util.ArrayList;
import java.util.Date;
import java.text.SimpleDateFormat;

public class BankAccount {
	
	SimpleDateFormat dateForm = new SimpleDateFormat("MM/dd/Y HH:mm");
	Date date = new Date();
	
	String clientName;
	String accountNumber;
	String accountType;
	ArrayList<AccountActivities> accountActivities = new ArrayList<AccountActivities>();
	int accountBalance = 0;
	
	public BankAccount(String clientName, String accountNumber, boolean isVadeli)
	{
		this.clientName = clientName;
		this.accountNumber = accountNumber;
		
		if(isVadeli == true)
		{
			accountType = "Vadeli";
		} 
		else 
		{
			accountType = "Vadesiz";
		}
	}
	
	public void deposit(int amount)
	{
		accountBalance += amount;
		System.out.printf("You have deposited %d liras in your account, your account balance is %d \n", amount, accountBalance);
		addAccountActivity(amount, accountBalance, "Deposit");
	}
	
	public void withdraw(int amount)
	{
		if(amount > accountBalance)
		{
			System.out.println("You don't have that amount of money in your bank account, please withdraw an amount you have.");
			System.out.printf("You have %d liras in your account.\n", accountBalance);
			
		} else {
			accountBalance -= amount;
			System.out.printf("You have withdrawn %d liras, %d liras left in account balance.\n", amount, accountBalance);
			addAccountActivity(amount, accountBalance, "Withdraw");
		}
		
	}
	
	void addAccountActivity(int transferAmount, int accountBalance, String activityType)
	{
		accountActivities.add(new AccountActivities(dateForm.format(date), accountNumber, activityType, transferAmount, accountBalance));
	}
	
	public void getAccountInfo()
	{
		System.out.println("Owner of the Account: " + clientName + ", Account Number: " + accountNumber + ", Account Type: " + accountType + ", Account Balance: " + accountBalance);
	}
	
	void getAllActivityInfo()
	{
		for(int i = 0; i < accountActivities.size(); i++)
		{
			accountActivities.get(i).getActivityInfo();
		}
	}
}
