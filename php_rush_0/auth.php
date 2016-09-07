<?php
function auth($login, $passwd)
{
	if ($login != NULL && $passwd != NULL)
	{
		$test = unserialize(file_get_contents("bdd/users.bd"));

		foreach ($test as $elem)
		{
			if ($elem['login'] == $login && $elem['passwd'] == hash(whirlpool, $passwd))
				return (TRUE);
		}
	}
	return (FALSE);
}
?>