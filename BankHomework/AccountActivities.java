
public class AccountActivities {
	String date;
	String accountNumber;
	String activityType;
	int amount;
	int accountBalance;
	
	public AccountActivities(String date, String accountNumber, String activityType, int amount, int accountBalance)
	{
		this.date = date;
		this.accountNumber = accountNumber;
		this.activityType = activityType;
		this.amount = amount;
		this.accountBalance = accountBalance;
	}
	
	public void getActivityInfo()
	{
		System.out.println("Activity Date: " + date + ", Account Number: " + accountNumber + ", Activity Type: " + activityType + ", Transfer Amount: " + amount + ", new Account Balance: " + accountBalance + " ");
	}
	
}
