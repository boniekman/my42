<?PHP
include "alert.php";
function add_to_basket($name)
{
	session_start();
	if (!$_SESSION["id_session"])
		$usr = "anon";
	else
		$usr = $_SESSION['id_session'];
	if (file_exists("basket") == FALSE)
		mkdir("basket");
	if (file_exists("basket/".$usr) == TRUE)
	{
		$basket = unserialize(file_get_contents("basket/".$usr));
		$basket[] = $name;
		file_put_contents("basket/".$usr, serialize($basket));
	}
	else
	{
		$basket = array();
		$basket[] = $name;
		file_put_contents("basket/".$usr, serialize($basket));
	}
}

function delete_all($name)
{
	session_start();
	if (!$_SESSION["id_session"])
		$usr = "anon";
	else
		$usr = $_SESSION['id_session'];
	if (file_exists("../basket") == FALSE)
		mkdir("../basket");
	if (file_exists("../basket/".$usr) == TRUE)
	{
		$basket = unserialize(file_get_contents("../basket/".$usr));
		unset($basket[array_search($name, $basket)]);
		file_put_contents("../basket/".$usr, serialize($basket));
	}
}

function delete_basket($name)
{
	session_start();
	if (!$_SESSION["id_session"])
		$usr = "anon";
	else
		$usr = $_SESSION['id_session'];
	if (file_exists("basket") == FALSE)
		mkdir("basket");
	if (file_exists("basket/".$usr) == TRUE)
		unlink("basket/".$usr);
}
?>
