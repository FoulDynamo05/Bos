public class Test {

	public static void main(String[] args) {
		BankAccount hesap = new BankAccount("Musteri", "51259636", true);
		hesap.deposit(300);
		hesap.deposit(500);
		hesap.withdraw(200);
		
		System.out.println();
		hesap.getAllActivityInfo();
		
		System.out.println();
		hesap.getAccountInfo();
	}

}
