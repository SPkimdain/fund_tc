package testcase.rule.security.ImproperAuthorizationChecker

import javax.naming.Context

object TestCase {
	fun getEnv(): HashMap<String, String> {
		val envMap: HashMap<String, String> = HashMap()
		return envMap
	}

	fun authorize(sSingleId: String, iFlag: Int, sServiceProvider: String, sUid: String, sPwd: String) {
		val env1 = System.getenv()
		val env2 = getEnv()
		val envMap: HashMap<String, String> = HashMap()
		val noneString = "none"
		val authentication = Context.SECURITY_AUTHENTICATION

		env1.put(Context.INITIAL_CONTEXT_FACTORY, "an_factory")
		env1.put(Context.PROVIDER_URL, sServiceProvider);
		// 익명으로 LDAP 인증을 사용
		env2.put(Context.SECURITY_AUTHENTICATION, noneString)				// @violation
		env1.put(authentication, "none")									// @violation
		System.getenv().put(authentication, "none")							// @violation
		env2[Context.SECURITY_AUTHENTICATION] = noneString					// @violation
		env1[authentication] = "none"										// @violation
		System.getenv()[authentication] = "none"							// @violation

		val safeString = "safe"
		env2.put(Context.SECURITY_AUTHENTICATION, safeString)				// good
		env1.put(authentication, "safe")									// good
		System.getenv().put(authentication, "safe")							// good
		env2[Context.SECURITY_AUTHENTICATION] = safeString					// good
		env1[authentication] = "safe"										// good
		System.getenv()[authentication] = "safe"							// good

		env1.put(Context.SECURITY_PRINCIPAL, sUid);
		env1.put(Context.SECURITY_CREDENTIALS, sPwd);
	}
}