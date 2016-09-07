<?php
include('config.php');
$ok = TRUE;
if ($_POST['submit'])
{
	if ($_POST['login'] && $_POST['passwd'] && $_POST['mail'] && $_POST['adresse'] && $_POST['CP'] && $_POST['ville'])
	{
		$login = $_POST['login'];
		$passwd = $_POST['passwd'];
		$test = unserialize(file_get_contents("bdd/users.bd"));
		foreach ($test as $key => $elem)
		{
				if ($elem['login'] == $login)
				{
					$ok = FALSE;
					break ;
				}
		}
		if ($ok == TRUE)
		{
			$test[] = array('login' => $login, 'passwd' => hash(whirlpool, $passwd), 'mail' => $_POST['mail'], 'adresse' => $_POST['adresse'], 'CP' => $_POST['CP'], 'ville' => $_POST['ville']);
			$result = serialize($test);
			file_put_contents("bdd/users.bd", $result); 
			if ($_SESSION['id_session'] === 'admin')
				header('Location: ./admin_user.php'); 
			else
			{
				$id_session = $login;
				$_SESSION['id_session'] = $id_session;
				header('Location: ./index.php');
			}
  		}
  		if (!$ok)
  			if ($_SESSION['id_session'] === 'admin')
				header('Location: ./admin_user.php'); 
			else
  				header('Location: ./create.php');
 	}
  	else
  		if ($_SESSION['id_session'] === 'admin')
				header('Location: ./admin_user.php'); 
		else
  			header('Location: ./create.php');
}
?>

<html>
<head>
	<meta charset="UTF-8">
	<title>42 SHOP</title>
	<link rel="stylesheet" href="index.css" />
</head>
<body>
	<div class="body_anonymous_error">
	</div>
	<div class="log_anonymous" >
	<h1 style="color: white; font-style: verdana; text-align: center; margin-top: 7vh;" >BIENVENUE SUR LE 42 SHOP !!<br/><br/>Remplis les champs ci-dessous :</h1>
	<div class="create">
		<form method="POST" action="create.php">
			Identifiant: <input style="margin-left: 2vw;" type="text" name="login" value=""></input>
			<br/>
			Mot de passe: <input style="margin-left: 0.5vw; margin-top: 2vh;" type="password" name="passwd" value=""></input>
			<br/>
			Mail: <input style="margin-left: 5vw; margin-top: 2vh;" type="email" name="mail" value=""></input>
			<br/>
			Adresse: <input style="margin-left: 3.2vw; margin-top: 2vh;" type="text" name="adresse" value=""></input>
			<br/>
			CP: <input style="margin-left: 6vw; margin-top: 2vh;" type="text" name="CP" value=""></input>
			<br/>
			Ville: <input style="margin-left: 5vw; margin-top: 2vh;" type="text" name="ville" value=""></input>
			<br/>
			<input style="margin-left: 0.5vw; margin-top: 2vh;" class="button_signup" type="submit" name="submit" value="VALIDER"></input>
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