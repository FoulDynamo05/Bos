
public class Weapon {
	int maxRange;
	Magazine mag;
	
	public Weapon(int maxRange)
	{
		this.maxRange = maxRange;
	}
	
	public void insertMag(Magazine mag)
	{
		this.mag = mag;
	}
	
	public void Fire(int range)
	{
		if(mag == null)
		{
			System.out.println("You can't shoot without inserting a magazine, please insert one");
		} 
		else if(range > maxRange) 
		{
			mag.Fire();
			System.out.println("You missed");
		} 
		else 
		{
			mag.Fire();
			System.out.println("Bullseye");
		}
		
	}
	
	public void Reload()
	{
		if(mag == null)
		{
			System.out.println("You can't reload without inserting a magazine, please insert one");
		
		} else {
			mag.Reload();
		}
		
	}

}
