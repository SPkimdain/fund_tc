import OpenSSL

func prepareContext(ctx: OpaquePointer) {

    SSL_CTX_set_verify(ctx, SSL_VERIFY_NONE, nil) //@violation
}

func prepareContext2(ctx: OpaquePointer) {

    SSL_CTX_set_verify(ctx, CURLOPT_SSL_VERIFYPEER, nil) //@violation
}

func prepareContext3(ctx: OpaquePointer) {

    SSL_CTX_set_verify(ctx, SSL_VERIFY_PEER, nil) //It's ok.
}
