<?php
include('config.php');
include('install.php');
include('utils/basket.php');
ft_install();

?>
	<!DOCTYPE html>
	<html>
	<head>
		<meta charset="UTF-8">
		<title>42 SHOP</title>
		<link rel="stylesheet" href="index.css" />
	</head>
	<body class="body_anonymous">
	<div class="log_anonymous">
<?php
if (!$_SESSION['id_session'])
{
?>
			<h3 class="connexion">Connexion</h3>
			<div class="connexion">
				<form method="POST" action="login.php">
					Identifiant: <input style="width: 9vw;" type="text" name="login" value=""></input>
					Mot de passe: <input style="width: 9vw;" type="password" name="passwd" value=""></input>
					<input class="button_signin" type="submit" name="submit" value="SIGN IN"></input>
				</form>
			</div>
			<div class="pos_singup"> 
				<form method="POST" action="create.php">
					<input class="button_signup" type="submit" name="sign_up" value="SIGN UP"></input>
				</form>
			</div>
			<div style="margin-left: 40vw; margin-top: 20vh; background-color: rgba(0, 0, 0, 0.8); width: 20vw; height: 8.3vh; text-align: center; border-radius: 15%">
			<h1 style=" color: white; text-align: center; font-style: verdana; margin-top: 3vh;"><br/>42 SHOP</h1>
			</div>
<?
}
else if ($_SESSION['id_session'] == "admin")
{
?>
	<div style="text-align: center;">
		<h1 style="color: white; text-align: center">Hello <?php echo $_SESSION['id_session']?><br/><br/>You have the POWER !!!!!</h1>
		<div style="margin-top: 10vh;">
			<form method="POST" action="modif.php">
				<input class="button_signin" style="width: 15vw; height: 5vh;" type="submit" name="submit" value="MODIFY ACCOUNT"></input>
			</form>
		</div>
		<div style="margin-top: 10vh;"> 
			<form method="POST" action="admin_user.php">
				<input class="button_signin" style="width: 15vw; height: 5vh;" type="submit" name="admin" value="admin"></input>
			</form>
		</div>
		<div style="margin-top: 10vh;">
			<form action="utils/add_product.php" method="POST">
				<input class="button_signin" style="width: 15vw; height: 5vh;" type="submit" value="Add product">
			</form>
		</div>
		<div style="margin-top: 10vh;">
			<form action="utils/chose_product.php" method="POST">
				<input class="button_signin" style="width: 15vw; height: 5vh;" type="submit" value="Change product">
			</form>
		</div>
		<div style="margin-top: 10vh;"> 
			<form method="POST" action="logout.php">
				<input class="button_signin" style="width: 15vw; height: 5vh;" type="submit" name="logout" value="logout"></input>
			</form>
		</div>
	</div>
	</body>
	</html>
<?php	
}
else
{
?>
	<h1 style="color: white; text-align: left">Hello <?php echo $_SESSION['id_session']?></h1>
	<div>
		<form method="POST" action="modif.php">
			<input class="modify" type="submit" name="submit" value="MODIFY ACCOUNT"></input>
		</form>
	</div>
	<div style="text-align: left"> 
		<form method="POST" action="logout.php">
			<input class="modify" type="submit" name="logout" value="logout"></input>
		</form>
	</div>
		</div>
<?php	
}
?>

<?PHP
$products = unserialize(file_get_contents("products/prods.db"));
$used = array();
$count = 0;
if (!$_GET["cat"]) 
{
	foreach ($products as $key=>$product)
	{
		if ($product["cat"])
		{
			foreach ($product["cat"] as $category)
			{
				if (in_array($category, $used) == FALSE)
				{
					echo '<a href="./index.php?cat='.$category.'">'.$category.'</a><BR />';
					$used[$count] = $category;
					$count++;
				}
			}
		}
	}
}
?>
<?PHP
$products = unserialize(file_get_contents("products/prods.db"));
foreach ($products as $key=>$product)
	if ($_POST[$product["name"]] == "add")
		add_to_basket($product["name"]);
?>
<?PHP
echo '<form method="POST"><table>';
$products = unserialize(file_get_contents("products/prods.db"));
if ($_GET["cat"] !== 0) 
{
	foreach ($products as $key=>$product)
		if (in_array($_GET["cat"], $product["cat"]))
			echo '<tr><td><img src="img/'.$product["photo"].'"></td><td><input type="submit" name="'.$product["name"].'" value="add"></td><tr>';
}
echo '</table></form>';
?>
	</body>
</html>
