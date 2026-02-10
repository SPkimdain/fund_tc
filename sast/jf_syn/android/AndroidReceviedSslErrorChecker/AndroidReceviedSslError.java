class AndroidReceviedSslError {

    @Override
    public void onReceivedSslError(WebView view, SslErrorHandler handler, SslError error) {
        super.onReceivedSslError(view, handler, error);
        handler.cancel();
        handler.proceed();  // @violation
    }


    @Override
    public void onReceivedSslError(WebView view, SslErrorHandler handler, SslError error) {
        if (DISABLE_SSL_CHECK_FOR_TESTING) {
            handler.proceed();  // @violation
        } else {
            super.onReceivedSslError(view, handler, error);
            sendErrorToListener(new FacebookDialogException(null, ERROR_FAILED_SSL_HANDSHAKE, null));
            handler.cancel();
            WebDialog.this.dismiss();
        }
    }

    @Override
    public void onReceivedSslError(WebView view, SslErrorHandler handler, SslError error) {
        String msg = "";
        switch (error.getPrimaryError()) {
            case SslError.SSL_EXPIRED:
            case SslError.SSL_IDMISMATCH:
            case SslError.SSL_NOTYETVALID:
            case SslError.SSL_UNTRUSTED:
            default:
                msg = "네트워크 오류입니다.\n(" + error.getPrimaryError() + ")";
                break;
        }

        CustomAlertDialogBuilder alertBuilder = new CustomAlertDialogBuilder(view.getContext())
                .setTitle("알림")
                .setMessage(msg + " 계속 진행 하시겠습니까?")
                .setCancelable(false)
                .setPositive("계속하기",
                        new DialogInterface.OnClickListener() {
                            public void onClick(DialogInterface dialog,
                                                int which) {
                                handler.proceed();  /* SAFE */
                                dialog.dismiss();
                            }
                        })
                .setNegative("닫기",
                        new DialogInterface.OnClickListener() {
                            public void onClick(DialogInterface dialog,
                                                int which) {
                                handler.cancel();
                                dialog.dismiss();
                                if (getActivity() != null)
                                    getActivity().finish();
                            }
                        });
        alertBuilder.setOnCancelListener(new DialogInterface.OnCancelListener() {
            @Override
            public void onCancel(DialogInterface dialog) {

            }
        });
        AlertDialog alertDlg = alertBuilder.create();
        alertDlg.show();
    }

}