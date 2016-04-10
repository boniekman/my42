<?PHP
include("name_tests.php");
include("alert.php");

if ($_POST["submit"] == "OK")
{
	if ($_POST["cat"] == "Categories" && !$_POST["new_cat"])
		alert("Chose Category");
	else if ($_POST["new_cat"] && ctype_alnum($_POST["new_cat"]) == FALSE)
		alert("Only alphanumeric characters in category name");
	else if (!$_POST["name"])
		alert("No name");
	else if (is_name_valid($_POST["name"]) == FALSE)
		alert("Alphanumeric characters or _ in product's name");
	else if (is_img_name_valid($_FILES["imgToUp"]["name"]) == FALSE)
		alert("Alphanumeric characters only and only .jpeg is supported");
	else
	{
		$products = unserialize(file_get_contents("../products/prods.db"));
		if (array_search($_POST["name"], array_column($products, "name")) == TRUE)
			alert("There is already a product named".$_POST["name"].". Change product name");
		else if (array_search($_POST["imgToUp"], array_column($products, "name")) == TRUE)
			alert("There is already an image named".$_POST["name"].". Change image name");
		else
		{
			if (move_uploaded_file($_FILES["imgToUp"]["tmp_name"], "../img/".$_FILES["imgToUp"]["name"]))
				alert("Image uploaded");
			else
				alert("There was an error while uploading an image. Image not set");
			if ($_POST["new_cat"])
				$products[] = array("name"=>$_POST["name"], "cat"=>array($_POST["new_cat"]), "photo"=>$_FILES["imgToUp"]["name"]);
			else
				$products[] = array("name"=>$_POST["name"], "cat"=>array($_POST["cat"]), "photo"=>$_FILES["imgToUp"]["name"]);
			file_put_contents("../products/prods.db", serialize($products));
		}
	}
}
?>
<html>
	<body>
		<form enctype="multipart/form-data" method="POST">
			<input name="name">
			<select name="cat">
				<option>Categories</option>
				<?PHP
					$products = unserialize(file_get_contents("../products/prods.db"));
					$used = array();
					$count = 0;
					foreach($products as $product)
					{
						if ($product["cat"])
						{
							foreach($product["cat"] as $category)
							{
								if (in_array($category, $used) == FALSE)
								{
									echo '<option>'.$category.'</option>';
									$used[$count] = $category;
									$count++;
								}
							}
						}
					}
			?>
			</select>
			<input type="input" name="new_cat">
			<input type="file" name="imgToUp" id="imgToUp">
			<BR />
			<input type="submit" name="submit" value="OK">
		</form>
		<a href="../admin_panel.html">RETURN</a>
		<BR />
	</body>
</html>
