<?PHP
	if (file_exists("products") == FALSE)
		mkdir("products");
	$prod = array();
	$prod[0] = array("name"=>"F_Green", "cat"=>array("Leaves"), "photo"=>"F_Green.jpeg");
	$prod[1] = array("name"=>"F_Yellow", "cat"=>array("Leaves"), "photo"=>"F_Yellow.jpeg");
	$prod[2] = array("name"=>"Big_stick", "cat"=>array("Sticks"), "photo"=>"Big_Stick.jpeg");
	$prod[3] = array("name"=>"F_Red", "cat"=>array("Leaves"), "photo"=>"F_Red.jpeg");
	file_put_contents("products/prods.db", serialize($prod));
?>
