<?
$data = "this is a data.";

$md5hash = md5($data); // @violation
$md5hash = hash("md5", $data); // @violation
$sha1hash = sha1($data); // @violation
$sha1hash = hash("sha1", $data); // @violation
$sha256hash = hash("sha256", $data);
$file_path = _PATH_UPLOAD_.time().'_'.MD5(mt_rand(10,100).$_FILES['Filedata']['name']);
