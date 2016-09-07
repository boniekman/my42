<?php
include('config.php');
if ($_SESSION['id_session'] === 'admin')
	$login = $_POST['login'];
else
	$login = $_SESSION['id_session'];

$test = unserialize(file_get_contents("bdd/users.bd"));
foreach ($test as $key => $elem)
{
	if ($elem['login'] == $login)
	{
		foreach ($elem as $key => $value)
		{
			if ($key === 'mail')
				$mail = $value;
			else if ($key === 'adresse')
				$adresse = $value;
			else if ($key === 'CP')
				$CP = $value;
			else if ($key === 'ville')
				$ville = $value;
			else if ($key === 'passwd' && $_SESSION['id_session'] === 'admin')
				$oldpw = $value;
		}
		break ;
	}
}

$ok = FALSE;
if ($_POST['submit_param'] == "OK")
{
	if ($_POST['mail'] && $_POST['adresse'] && $_POST['CP'] && $_POST['ville'])
	{
		foreach ($test as $key => $elem)
		{
			if ($elem['login'] == $login)
			{
				foreach ($elem as $key2 => $value)
				{
					if ($key2 === 'mail' && $value !== $_POST['mail'])
					{
						$test[$key]['mail'] = $_POST['mail'];
						$ok = TRUE;
					}
					else if ($key2 === 'adresse' && $value !== $_POST['adresse'])
					{
						$test[$key]['adresse'] = $_POST['adresse'];
						$ok = TRUE;
					}
					else if ($key2 === 'CP' && $value !== $_POST['CP'])
					{
						$test[$key]['CP'] = $_POST['CP'];
						$ok = TRUE;
					}
					else if ($key2 === 'ville' && $value !== $_POST['ville'])
					{
						$test[$key]['ville'] = $_POST['ville'];
						$ok = TRUE;
					}
				}
				break ;
			}
		}
		if ($ok == TRUE)
		{
			$result = serialize($test);
			file_put_contents("bdd/users.bd", $result);
			if ($_SESSION['id_session'] === 'admin')
				header('Location: ./admin_user.php'); //a change par admin_panel.html
			else
			{
				header('Location: ./index.php');
			}
		}			
		if (!$ok)
		{
			if ($_SESSION['id_session'] === 'admin')
				header('Location: ./admin_user.php');
			else
				header('Location: ./modif.php');
		}
	}
	else 
	{
		if ($_SESSION['id_session'] === 'admin')
			header('Location: ./admin_user.php');
		else
			header('Location: ./modif.php');
	}
}
else if ($_POST['submit'] == "OK")
{
	if ($login)
	{
		if ($_SESSION['id_session'] === 'admin')
			$newpw = $_POST['passwd'];	
		else
		{
			$oldpw = hash(whirlpool, $_POST['oldpw']);
			$newpw = $_POST['newpw'];
		}
		foreach ($test as $key => $elem)
		{
			if ($elem['login'] == $login && $elem['passwd'] == $oldpw)
			{ 
				if ($elem['passwd'] == hash(whirlpool, $newpw))
				{
					$ok = FALSE;
				}
				else
				{
					$test[$key]['passwd'] = hash(whirlpool, $newpw);
					$ok = TRUE;
				}
			}
		}
		if ($ok == TRUE)
		{
			$result = serialize($test);
			file_put_contents("bdd/users.bd", $result);
			if ($_SESSION['id_session'] === 'admin')
				header('Location: ./admin_user.php'); //a change par admin_panel.html
			else
				header('Location: ./index.php');
		}			
		if (!$ok)
		{
			if ($_SESSION['id_session'] === 'admin')
				header('Location: ./admin_user.php'); //a change par admin_panel.html
			else
				header('Location: ./modif.php');
		}
	}
	else 
	{
		if ($_SESSION['id_session'] === 'admin')
				header('Location: ./admin_user.php'); //a change par admin_panel.html
			else
				header('Location: ./modif.php');
	}
}
else if ($_POST['submit_del_acc'] == "DELETE ACCOUNT")
{
	foreach ($test as $key => $elem)
	{
		if ($elem['login'] == $login)
		{
			unset($test[$key]);
			$result = serialize($test);
			file_put_contents("bdd/users.bd", $result);
			break ;
		}
	}
	if ($_SESSION['id_session'] === 'admin')
		header('Location: ./admin_user.php'); //a change par admin_panel.html
	else
	{
		session_destroy();
		header('Location: ./index.php');
	}
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
	<div class="log_anonymous" style="text-align: center">
		<div style="margin-top: 10vh;">
			<h1 style="font-style: verdana; color: white;">CHANGE PASSWORD!!!</h1>
			<form style="font-style: verdana; color: white;" method="POST" action="modif.php">
				<input type="hidden" name="login" value="<?php echo $login; ?>"></input>
				Ancien mot de passe: <input  type="password" name="oldpw" value=""></input>
				Nouveau mot de passe: <input  type="password" name="newpw" value=""></input>
				<input style=" width: 100px; margin-left: 10px; background-color: #82C945; border-radius: 30px;" type="submit" name="submit" value="OK"></input>
			</form>
		</div>
		<div style="margin-top: 20vh;">
			<h1 style="font-style: verdana; color: white;">CHANGE PARAMETERS!!!</h1>
			<form style="font-style: verdana; color: white;" method="POST" action="modif.php">
				Mail: <input style="margin-left: 31px" type="email" name="mail" value="<?php echo $mail; ?>"></input>
				<br/>
				Adresse: <input style="margin-left: 9px" type="text" name="adresse" value="<?php echo $adresse; ?>"></input>
				<br/>
				CP: <input style="margin-left: 41px" type="text" name="CP" value="<?php echo $CP; ?>"></input>
				<br/>
				Ville: <input style="margin-left: 30px" type="text" name="ville" value="<?php echo $ville; ?>"></input>
				<br/>
				<input style=" width: 100px;  margin-top: 10px; background-color: #82C945; border-radius: 30px;" type="submit" name="submit_param" value="OK"></input>
			</form>
		</div>
		<div style="margin-top: 20vh;">
			<h1 style="font-style: verdana; color: white;">DELETE ACCOUNT</h1>
			<form  style="font-style: verdana; color: white;"method="POST" action="modif.php">
				<input style=" width: 150px;  background-color: #E2935A; border-radius: 30px;" type="submit" name="submit_del_acc" value="DELETE ACCOUNT"></input>
			</form>
		</div>
		<div style="margin-top: 10vh;">
			<form  style="font-style: verdana; color: white; text-align: left;" method="POST" action="index.php">
				<input class="button_signin" style="width: 8vw; height: 5vh;" type="submit" name="submit" value="HOME"></input>
			</form>
		</div>
		</div>
</body>
</html>