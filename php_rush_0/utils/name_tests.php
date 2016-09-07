<?PHP
function is_name_valid($str)
{
	$tab = str_split($str);
	foreach($tab as $char)
	{
		if (ctype_alnum($char) == FALSE && $char !== '_')
			return (FALSE);
	}
	return (TRUE);
}

function is_img_name_valid($str)
{
	if (preg_match("/^[[:alnum:]]+\.jpeg$/", $str) == 1)
		return (TRUE);
	else
		return (FALSE);
}
?>
