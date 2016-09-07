<?PHP
include "basket.php";
session_start();
$products = unserialize(file_get_contents("../products/prods.db"));
foreach ($products as $key=>$product)
	if ($_POST[$product["name"]] == "delete")
		delete_all($product["name"]);
?>
<html>
<body>
<form method="POST">
<table style="margin-left: 50px; background-color: #A5EDE4; border-radius: 10px;">
<tr>
<?PHP
if (!$_SESSION["id_session"])
	$usr = "anon";
else
	$usr = $_SESSION["id_session"];
$basket= unserialize(file_get_contents("../basket/".$usr));
$products = unserialize(file_get_contents("../products/prods.db"));
foreach($basket as $key=>$elem)
	if ($elem)
		echo '<tr><td>'.$elem.'</td><td><input type="submit" name="'.$elem.'" value="delete"></td></tr>';
?>
</tr>
</form>
<body>
<html>
