Function genReceiptURL(baseURL)
    dim randNum
    randNum = Rnd() '@violation
    genReceiptURL = baseURL & randNum & ".html"
End Function