Catalog = CreateObject("ADOX.Catalog")
Catalog.ActiveConnection = conn
Catalog.Create Request.Form("catalog") '@violation
