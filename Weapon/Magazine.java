
public class Magazine {
	
	int maxAmmo;
	int currentAmmo;
	
	public Magazine(int maxAmmo, int currentAmmo)
	{
		this.maxAmmo = maxAmmo;
		if(currentAmmo > maxAmmo)
		{
			this.currentAmmo = maxAmmo;
			
		} else {
			
			this.currentAmmo = currentAmmo;
			
		}
		
	}
	
	public void Fire()
	{
		if(currentAmmo == 0)
		{
			System.out.println("Your mag is empty please reload");
			
		} else {
			currentAmmo--;
			System.out.println("Ammo left:" + currentAmmo);
		}
		
	}
	
	public void Reload()
	{
		currentAmmo = maxAmmo;
		System.out.println("Reloaded, ammo left: " + currentAmmo);
	}
}
