from flask import request
from django.shortcuts import render
import pickle
import hmac
import hashlib
import yaml


def neverusetest():
    myfile = file_open_wrapper('stored.dat')
    pickle.dump(some_object, myfile)

    loaded = pickle.load(myfile)  # @violation


def call_analysis_test(some_obj):
    myfile = open('stored.dat', 'rw')
    pickle_dump_wrapper(myfile, some_obj)
    pickle_load_wrapper(myfile)  # @violation
    myfile.close()


def tainttest():
    myfile = open('stored.dat', 'rw')

    pickled_data = pickle.dumps(some_object, myfile)
    pickle_digest = hmac.new('shared-key', pickled_data, hashlib.sha256).hexdigest()

    myfile.write(pickled_data)

    loaded_data = myfile.read()
    loaded_digest = hmac.new('shared-key', loaded_data, hashlib.sha256).hexdigest()
    if hmac.compare_digest(pickle_digest, loaded_digest):
        loaded = pickle.loads(loaded_data)
    myfile.close()


def file_open_wrapper(name):
    return open(name, 'rw')


def pickle_dump_wrapper(file, obj):
    pickle.dump(obj, file)


def pickle_load_wrapper(file):
    return pickle.load(file)


@app.route('/pickle')
def pickle_loads():
    file = request.files['pickle']
    pickle.load(file)  # @violation


@app.route('/yaml')
def yaml_load1():
    data = request.GET.get("data")
    yaml.load(data, Loader=yaml.Loader)  # @violation


@app.route('/yaml')
def yaml_load2():
    data = request.GET.get("data")
    yaml.load(data)  # @violation


def load_user_object1(request):
    userinfo = bytes(request.POST.get('userinfo', ''), encoding="utf-8")
    hmac.new('shared-key', userinfo, hashlib.sha256).hexdigest()

    # 사용자로부터 입력받은 알 수 없는 데이터를 직렬화
    user_obj = pickle.loads(userinfo)  # @violation
    return render(request, '/load_user_obj.html', {'obj': user_obj})


def load_user_object2(request):
    userinfo = bytes(request.POST.get('userinfo', ''), encoding="utf-8")
    m = hmac.new(key=b'secret_key', digestmod=hashlib.sha512)  # good
    m.update(userinfo)

    # 사용자로부터 입력받은 알 수 없는 데이터를 직렬화
    user_obj = pickle.loads(userinfo)  # @violation
    return render(request, '/load_user_obj.html', {'obj': user_obj})


def load_user_object3(request):
    hash_pickle = bytes(request.POST.get('hash_pickle', ''), encoding="utf-8")
    userinfo = bytes(request.POST.get('userinfo', ''), encoding="utf-8")
    # HMAC 검증을 위한 비밀키는 안전하게 저장하여 사용
    m = hmac.new(key=b'secret_key', digestmod=hashlib.sha512)  # good
    m.update(userinfo)
    # 전달받은 해시값(hash_pickle)과 직렬화 데이터(userinfo)의
    # 해시값을 비교하여 검증
    if hmac.compare_digest(m.digest(), hash_pickle):
        user_obj = pickle.loads(userinfo)
        return render(request, '/load_user_obj.html', {'obj': user_obj})
    else:
        return render(request, '/error.html', {'error': '직렬화 오류입니다.'})


@app.route('/yaml')
def yaml_load():
    data = request.GET.get("data")
    yaml.load(data)  # @violation


@app.route('/yaml')
def yaml_load():
    data = request.GET.get("data")
    yaml.safe_load(data)  # good
