<?php
include('config.php');
include('auth.php');
$login = $_POST['login'];
$passwd = $_POST['passwd'];

if (!auth($login, $passwd))
{
	$_SESSION['id_session'] = ""; 
?>
	<html>
	<head>
		<meta charset="UTF-8">
		<title>42 SHOP</title>
		<link rel="stylesheet" href="index.css" />
	</head>
	<body >
	<div class = "body_anonymous_error">
	</div>
	<div class="log_anonymous">
	<h1 style="color: white;">TRY AGAIN !!!</h1>	
		<div > 
			<form style="color: white;" method="POST" action="login.php">
				Identifiant: <input type="text" name="login" value=""></input>
				Mot de passe: <input type="password" name="passwd" value=""></input>
				<input class="button_signin" type="submit" name="submit" value="SIGN IN"></input>
			</form>
		</div>
	</div>	
	<div style="position: absolute; bottom: 120px;">
		<form method="POST" action="index.php">
			<input class="button_signin" type="submit" name="submit" value="HOME"></input>
		</form>
	</div>
	</body>
	</html>
<?php
}
else
{
	$id_session = $login;
	$_SESSION['id_session'] = $id_session;
	header('Location: ./index.php');
	exit();
}
?>