
public class Deneme {

	public static void main(String[] args) {
		Weapon silah = new Weapon(40);
		silah.insertMag(new Magazine(30,30));
		silah.Fire(5);
		silah.Fire(45);
		silah.Reload();
		silah.Fire(25);
		
		Weapon silah2 = new Weapon(45);
		silah2.Fire(32);
		silah2.insertMag(new Magazine(50, 50));
		silah2.Fire(50);
	}


}
