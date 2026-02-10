import io.jsonwebtoken.JwtException;
import io.jsonwebtoken.Jwts;
import io.jsonwebtoken.security.Keys;
import io.jsonwebtoken.SignatureAlgorithm;
import org.springframework.stereotype.Service;

import java.security.Key;
import javax.crypto.SecretKey;
import java.util.Calendar;
import java.util.Date;

import com.auth0.jwt.JWT;
import com.auth0.jwt.JWTCreator;
import com.auth0.jwt.algorithms.Algorithm;
import com.auth0.jwt.exceptions.JWTCreationException;

public class ImproperSignatureJWTTestCase {

    private SecretKey key = Keys.secretKeyFor(SignatureAlgorithm.HS256);
    private int tokenExpirationMsec = 1800000;

    public String createToken() {
        Date now = new Date();
        Calendar calendar = Calendar.getInstance();
        calendar.add(Calendar.MILLISECOND, tokenExpirationMsec);
        Date expiryDate =  calendar.getTime();
        String temp = Jwts.builder().setSubject("Bonjour Park").setIssuedAt(now).setExpiration(expiryDate).compact();   // @violation

        return temp;
    }

    public boolean BadValidateToken(String authToken) throws JwtException {

        try {
            Jwts.parser()   // @violation
                    .setSigningKey(key)
                    .parse(token).getBody();
            return true;
        } catch (JwtException e) {
            e.printStackTrace();
        }
        return false;
    }

    public boolean GoodvalidateToken(String authToken) throws JwtException {

        try {
            Jwts.parser().setSigningKey(key).parseClaimsJws(authToken).getBody();
            return true;
        } catch (JwtException e) {
            e.printStackTrace();
        }
        return false;
    }

    public static String BadSign(String account, String currentTimeMillis) {
        String secret = account + Base64ConvertUtil.decode(encryptJWTKey);
        Date date = new Date(System.currentTimeMillis() + Long.parseLong(accessTokenExpireTime) * 1000);
        return JWT.create() // @violation
                .withSubject("SUBJECT")
                .sign(Algorithm.none());
    }

    public static String GoodSign(String account, String currentTimeMillis) {
        String secret = account + Base64ConvertUtil.decode(encryptJWTKey);
        Date date = new Date(System.currentTimeMillis() + Long.parseLong(accessTokenExpireTime) * 1000);
        Algorithm algorithm = Algorithm.HMAC256(secret);
        return JWT.create()
                .withSubject("SUBJECT")
                .sign(algorithm);
    }

    public TOKEN BadDecode(final String token) {

        final JWTVerifier jwtVerifier = JWT.require(Algorithm.none()).withSubject("SUBJECT").build();// @violation
        DecodedJWT decodedJWT = jwtVerifier.verify(token);
        return new TOKEN(decodedJWT.getClaim("userIdx").asLong().intValue());

    }

    public TOKEN GoodDecode(final String token) {

        final JWTVerifier jwtVerifier = JWT.require(Algorithm.HMAC256(SECRET)).withSubject("SUBJECT").build();
        DecodedJWT decodedJWT = jwtVerifier.verify(token);
        return new TOKEN(decodedJWT.getClaim("userIdx").asLong().intValue());

    }
}