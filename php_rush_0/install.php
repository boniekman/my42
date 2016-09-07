<?php
function ft_install()
{
	if (!file_exists("bdd"))
		mkdir("bdd");

	if (!file_exists("bdd/users.bd"))
	{
		$tab[0] = array('login' => "admin", 'passwd' => hash(whirlpool, "admin42"), 'mail' => "admin@42shop.fr", 'adresse' => "30 rue de la palanque", 'CP' => "66430", 'ville' => "BOMPAS");
		$tab[1] = array('login' => "toto", 'passwd' => hash(whirlpool, "titi"), 'mail' => "toto@42shop.fr", 'adresse' => "98 avenue dela liberte", 'CP' => "75680", 'ville' => "PARIS");
		$tab[2] = array('login' => "mika", 'passwd' => hash(whirlpool, "lolo_69"), 'mail' => "mika@42shop.fr", 'adresse' => "2 rue du ricard", 'CP' => "13000", 'ville' => "MARSEILLE");
		file_put_contents("bdd/users.bd", serialize($tab));
	}
	if (file_exists("products") == FALSE)
		mkdir("products");
	if (!file_exists("products/prods.db"))
	{
		$prod = array();
		$prod[0] = array("name"=>"F_Green", "cat"=>array("Leaves"), "photo"=>"F_Green.jpeg");
		$prod[1] = array("name"=>"F_Yellow", "cat"=>array("Leaves"), "photo"=>"F_Yellow.jpeg");
		$prod[2] = array("name"=>"Big_stick", "cat"=>array("Sticks"), "photo"=>"Big_Stick.jpeg");
		$prod[3] = array("name"=>"F_Red", "cat"=>array("Leaves"), "photo"=>"F_Red.jpeg");
		file_put_contents("products/prods.db", serialize($prod));
	}
}
?>
