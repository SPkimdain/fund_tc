import os
import stat

def getPermission():
    return 777

def incorrect_permission_assignment_for_critical_resource_1():
    filename = "test.txt"
    os.chmod(filename, 0o777)                                       # @violation

def incorrect_permission_assignment_for_critical_resource_2():
    filename = "test.txt"
    os.fchmod(filename, 0o777)                                      # @violation

def incorrect_permission_assignment_for_critical_resource_3():
    filename = "test.txt"
    os.lchmod(filename, 0o777)                                      # @violation

def incorrect_permission_assignment_for_critical_resource_4():
    os.umask(0)                                                     # @violation
    os.umask(1)                                                     # @violation
    os.umask(7)                                                     # @violation

def incorrect_permission_assignment_for_critical_resource_5():
    perm = 777
    fileName = 'test'
    extension = ".txt"
    os.system('chmod ' + perm + ' -R ' + fileName + extension)      # @violation

def incorrect_permission_assignment_for_critical_resource_6():
    perm = getPermission()
    fileName = getFileName()                                        # filename is unknown value -> pass ( Ex) 'chmod 777 -R .txt')
    os.system('chmod ' + perm + ' -R ' + fileName + ".txt")         # @violation

def incorrect_permission_assignment_for_critical_resource_7():
    os.system('umask 0')                                            # @violation

def incorrect_permission_assignment_for_critical_resource_8():
    cmd = 'umask 0'
    os.system(cmd)                                                  # @violation

def incorrect_permission_assignment_for_critical_resource_9():
    filename = "test.txt"
    os.chmod(filename, 0o700)                                       # good

def incorrect_permission_assignment_for_critical_resource_10():
    os.umask(0o77)                                                  # good
    os.umask(0o077)                                                 # good

def incorrect_permission_assignment_for_critical_resource_11():
    os.system('umask 077')                                          # good

def incorrect_permission_assignment_for_critical_resource_12():
    perm = getPerm()
    os.system('chmod ' + perm + ' -R test.txt')                     # perm is unknown value -> pass

def incorrect_permission_assignment_for_critical_resource_13():
    #모든 사용자가 읽기, 쓰기, 실행 권한을 가지게 됨.
    os.chmod('/root/system_config', 0o777)                          # @violation

    with open("/root/system_config", 'w') as f:
        f.write("your config is broken")

def incorrect_permission_assignment_for_critical_resource_14():
    #소유자 외에는 아무런 권한을 주지 않음.
    os.chmod('/root/system_config', 0o700)                          # good

    with open("/root/system_config", 'w') as f:
        f.write("your config is broken")

def incorrect_permission_assignment_for_critical_resource_15():
    filename = "test.txt"
    os.chmod(filename, 0o100)                                       # good
    os.chmod(filename, 0o200)                                       # good
    os.chmod(filename, 0o400)                                       # good
    os.chmod(filename, 0o700)                                       # good
    os.chmod(filename, 0o1000)                                      # good
    os.chmod(filename, stat.S_IXUSR)                                # good
    os.chmod(filename, stat.S_IWUSR)                                # good
    os.chmod(filename, stat.S_IRUSR)                                # good
    os.chmod(filename, stat.S_IRWXU)                                # good
    os.chmod(filename, stat.S_ISVTX)                                # good
    os.chmod(filename, 0o101)                                       # @violation
    os.chmod(filename, 0o220)                                       # @violation
    os.chmod(filename, 0o444)                                       # @violation
    os.chmod(filename, 0o770)                                       # @violation
    os.chmod(filename, 0o1001)                                      # @violation
    os.chmod(filename, stat.S_ISGID)                                # @violation
    os.chmod(filename, stat.S_IRGRP)                                # @violation
    os.chmod(filename, stat.S_IWGRP)                                # @violation
    os.chmod(filename, stat.S_IXGRP)                                # @violation
    os.chmod(filename, stat.S_IROTH)                                # @violation