
Public Class DataGlob


  <HttpPost()> '@violation
  Function Create(movie As Movie) As ActionResult
      'If ModelState.IsValid Then
          db.Movies.Add(movie)
          db.SaveChanges()
          Return RedirectToAction("Index")
      'End If

      Return View(movie)
  End Function

End Class
