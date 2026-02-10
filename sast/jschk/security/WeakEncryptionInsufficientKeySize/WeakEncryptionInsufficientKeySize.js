const {publicKey, privateKey} = crypto.generateKeyPairSync('rsa', {	// @violation
	modulusLength: 1024,
	publicKeyEncoding: {type: "spki", format: 'pem'},
	privateKeyEncoding: {type: "pkcs8", format: 'pem'}
});

const {publicKey, privateKey} = crypto.generateKeyPairSync('ec', { // @violation
	namedCurve: 'secp192k1',
	publicKeyEncoding: {type: "spki", format: 'der'},
	privateKeyEncoding: {type: "pkcs8", format: 'der'}
});

const {publicKey, privateKey} = crypto.generateKeyPairSync('rsa', {
	modulusLength: 2048,
	publicKeyEncoding: {type: "spki", format: 'pem'},
	privateKeyEncoding: {type: "pkcs8", format: 'pem'}
});

const {publicKey, privateKey} = crypto.generateKeyPairSync('ec', {
	namedCurve: 'secp256k1',
	publicKeyEncoding: {type: "spki", format: 'der'},
	privateKeyEncoding: {type: "pkcs8", format: 'der'}
});

