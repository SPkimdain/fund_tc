package testcase.rule.security.LdapInjectionChecker

import java.util.*
import javax.naming.Context
import javax.naming.NamingException
import javax.naming.directory.InitialDirContext
import javax.naming.directory.SearchControls
import javax.naming.directory.SearchResult
import javax.naming.ldap.InitialLdapContext
import javax.servlet.http.HttpServletRequest

object TestCase {
	fun violation1(request: HttpServletRequest) {							// 외부 입력
		val userSN = request.getParameter("userSN")
		val userPassword = request.getParameter("userPassword")

		val env : Hashtable<String, String> = Hashtable()
		env[Context.INITIAL_CONTEXT_FACTORY] = "com.sun.jndi.ldap.LdapCtxFactory"
		env[Context.PROVIDER_URL] = "ldap://localhost:389/o=rootDir"
		try {
			val dctx = InitialDirContext(env)
			val sc = SearchControls()
			val attributeFilter = arrayOf("cn", "mail")
			sc.returningAttributes = attributeFilter
			sc.searchScope = SearchControls.SUBTREE_SCOPE
			val base = "dc=example,dc=com"
			val filter = "(&(sn=$userSN)(userPassword=$userPassword))"		// userSN와 userPassword에 '*' 들어갈 경우 항상 True가 됨
			val results = dctx.search(base, filter, sc) 					// @violation
			while (results.hasMore()) {
				val sr = results.next() as SearchResult
				val attrs = sr.attributes
				val attr = attrs.get("cn")
			}
			dctx.close()
		} catch (e : NamingException) {
			logger.error("NamingException")
		}
	}

	fun violation2(request: HttpServletRequest) {							// 외부 입력
		val userSN = request.getParameter("userSN")
		val userPassword = request.getParameter("userPassword")
	
		val env : Hashtable<String, String> = Hashtable()
		env[Context.INITIAL_CONTEXT_FACTORY] = "com.sun.jndi.ldap.LdapCtxFactory"
		env[Context.PROVIDER_URL] = "ldap://localhost:389/o=rootDir"
		try {
			val ctx = InitialLdapContext(env, null)
			ctx.requestControls = null;
			val sc = SearchControls()
			sc.searchScope = SearchControls.SUBTREE_SCOPE;
			sc.timeLimit = 30000;
			val base = "dc=example,dc=com"
			val filter = "(&(sn=$userSN)(userPassword=$userPassword))"		// userSN와 userPassword에 '*' 들어갈 경우 항상 True가 됨
			val results = ctx.search(base, filter, sc) 						// @violation
			while (results.hasMore()) {
				val sr = results.next() as SearchResult
				val attrs = sr.attributes
				val attr = attrs.get("cn")
			}
			ctx.close()
		} catch (e : NamingException) {
			logger.error("NamingException")
		}
	}

	fun good(request: HttpServletRequest) {									// 외부 입력
		val userSN = request.getParameter("userSN")
		val userPassword = request.getParameter("userPassword")

		val env : Hashtable<String, String> = Hashtable()
		env[Context.INITIAL_CONTEXT_FACTORY] = "com.sun.jndi.ldap.LdapCtxFactory"
		env[Context.PROVIDER_URL] = "ldap://localhost:389/o=rootDir"
		try {
			val dctx = InitialDirContext(env)
			val sc = SearchControls()
			val attributeFilter = arrayOf("cn", "mail")
			sc.returningAttributes = attributeFilter
			sc.searchScope = SearchControls.SUBTREE_SCOPE
			val base = "dc=example,dc=com"

			if(userSN.matches(Regex("[\\w\\s]*")) && userPassword.matches(Regex("[\\w]*"))) {
				val filter = "(&(sn=$userSN)(userPassword=$userPassword))"
				val results = dctx.search(base, filter, sc)					// good
				while (results.hasMore()) {
					val sr = results.next() as SearchResult
					val attrs = sr.attributes
					val attr = attrs.get("cn")
				}
			}
			dctx.close()
		} catch (e : NamingException) {
			logger.error("NamingException")
		}
	}
}