package ti.helper;

import java.util.Map;

import javax.persistence.EntityManager;
import javax.persistence.EntityManagerFactory;
import javax.persistence.EntityTransaction;
import javax.persistence.FlushModeType;
import javax.persistence.LockModeType;
import javax.persistence.TypedQuery;
import javax.persistence.criteria.CriteriaBuilder;
import javax.persistence.criteria.CriteriaQuery;
import javax.persistence.metamodel.Metamodel;

public class EntityManagerImpl implements EntityManager {

    public void clear() {        

    }

    public void close() {        

    }

    public boolean contains(Object arg0) {
        return false;
    }

    public javax.persistence.Query createNamedQuery(String arg0) {
        return null;
    }

    public <T> TypedQuery<T> createNamedQuery(String arg0, Class<T> arg1) {
        return null;
    }

    public javax.persistence.Query createNativeQuery(String arg0) {
        return null;
    }

    public javax.persistence.Query createNativeQuery(String arg0, Class arg1) {
        return null;
    }

    public javax.persistence.Query createNativeQuery(String arg0, String arg1) {
        return null;
    }

    public javax.persistence.Query createQuery(String arg0) {
        return null;
    }

    public <T> TypedQuery<T> createQuery(CriteriaQuery<T> arg0) {
        return null;
    }

    public <T> TypedQuery<T> createQuery(String arg0, Class<T> arg1) {
        return null;
    }

    public void detach(Object arg0) {

    }

    public <T> T find(Class<T> arg0, Object arg1) {
        
        return null;
    }

    public <T> T find(Class<T> arg0, Object arg1, Map<String, Object> arg2) {
        
        return null;
    }

    public <T> T find(Class<T> arg0, Object arg1, LockModeType arg2) {
        
        return null;
    }

    public <T> T find(Class<T> arg0, Object arg1, LockModeType arg2,
                      Map<String, Object> arg3) {
        
        return null;
    }

    public void flush() {
        

    }

    public CriteriaBuilder getCriteriaBuilder() {
        
        return null;
    }

    public Object getDelegate() {
        
        return null;
    }

    public EntityManagerFactory getEntityManagerFactory() {
        
        return null;
    }

    public FlushModeType getFlushMode() {
        
        return null;
    }

    public LockModeType getLockMode(Object arg0) {
        
        return null;
    }

    public Metamodel getMetamodel() {
        
        return null;
    }

    public Map<String, Object> getProperties() {
        
        return null;
    }

    public <T> T getReference(Class<T> arg0, Object arg1) {
        
        return null;
    }

    public EntityTransaction getTransaction() {
        
        return null;
    }

    public boolean isOpen() {
        
        return false;
    }

    public void joinTransaction() {
        

    }

    public void lock(Object arg0, LockModeType arg1) {
        

    }

    public void lock(Object arg0, LockModeType arg1,
                     Map<String, Object> arg2) {
        

    }

    public <T> T merge(T arg0) {
        
        return null;
    }

    public void persist(Object arg0) {
        

    }

    public void refresh(Object arg0) {
        

    }

    public void refresh(Object arg0, Map<String, Object> arg1) {
        

    }

    public void refresh(Object arg0, LockModeType arg1) {
        

    }

    public void refresh(Object arg0, LockModeType arg1,
                        Map<String, Object> arg2) {
        

    }

    public void remove(Object arg0) {
        

    }

    public void setFlushMode(FlushModeType arg0) {
        

    }

    public void setProperty(String arg0, Object arg1) {
        

    }

    public <T> T unwrap(Class<T> arg0) {
        return null;
    }
}