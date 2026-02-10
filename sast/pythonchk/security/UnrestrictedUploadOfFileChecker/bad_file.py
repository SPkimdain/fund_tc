from django.core.files.storage import default_storage
from django.core.files.base import File
from django.http import HttpResponseRedirect
from django.shortcuts import render
from django.core.files.storage import FileSystemStorage
from forms import UploadFileForm
import os


def upload_loop_ds(request):
    files = request.FILES
    for f in files.values():
        path = default_storage.save('upload/', File(f))  # @violation


def upload_access_write_chunk(request):
    if request.method == 'POST':
        form = UploadFileForm(request.POST, request.FILES)
        if form.is_valid():
            target = request.FILES['file']
            handle_uploaded_file(target, target.name)  # @violation
            return HttpResponseRedirect('/success/')
    else:
        form = UploadFileForm()
    return render(request, 'upload.html', {'form': form})


def upload_access_write_chunk2(request):
    if request.method == 'POST':
        form = UploadFileForm(request.POST, request.FILES)
        if form.is_valid():
            target = request.FILES['file']
            if target.name.endswith(".txt"):
                handle_uploaded_file(target, target.name)  # safe
            return HttpResponseRedirect('/success/')
    else:
        form = UploadFileForm()
    return render(request, 'upload.html', {'form': form})


def upload_access_ds(request):
    if request.method == 'POST':
        form = UploadFileForm(request.POST, request.FILES)
        if form.is_valid():
            path = default_storage.save('upload/', File(request.FILES['file']))  # @violation
            return HttpResponseRedirect('/success/')
    else:
        form = UploadFileForm()
    return render(request, 'upload.html', {'form': form})


def handle_uploaded_file(f, name):
    with open('some/file/' + name, 'wb+') as dest:
        for chunk in f.chunks():
            dest.write(chunk)


def file_upload(request):
    if request.FILES['upload_file']:
        # 사용자로부터 업로드 되는 파일에 대해 검증 없이 저장하고 있어
        # 안전하지 않다.
        upload_file = request.FILES['upload_file']
        fs = FileSystemStorage(location='media/screenshot', base_url='media/screenshot')
        # 업로드 하는 파일에 대한 크기, 개수, 확장자 등을 검증 하지 않음.
        filename = fs.save(upload_file.name, upload_file)   # @violation
        return render(request, '/success.html', {'filename': filename})
    return render(request, '/error.html', {'error': '파일 업로드 실패'})


# 업로드 하는 파일에 대한 개수, 크기, 확장자 제한
FILE_COUNT_LIMIT = 5
# 업로드 하는 파일의 최대 사이즈 제한 예 ) 5MB - 5*1024*1024
FILE_SIZE_LIMIT = 5242880
# 허용하는 확장자는 화이트리스트로 관리한다.
WHITE_LIST_EXT = ['.jpg', '.jpeg']


def file_upload(request):
    files = request.FILES

    # 파일 개수 제한
    if len(files) == 0 or len(files) > FILE_COUNT_LIMIT:
        return render(request, '/error.html', {'error': '파일 개수 초과'})

    for filename, upload_file in files.items():
        # 파일 타입 체크
        if upload_file.content_type != 'image/jpeg':
            return render(request, '/error.html', {'error': '파일 타입 오류'})
        # 파일 크기 제한
        if upload_file.size > FILE_SIZE_LIMIT:
            return render(request, '/error.html', {'error': '파일 사이즈 오류'})
        # 파일 확장자 검사
        file_name, file_ext = os.path.splitext(upload_file.name)
        if file_ext.lower() not in WHITE_LIST_EXT:
            return render(request, '/error.html', {'error': '파일 타입 오류'})

    fs = FileSystemStorage(location='media/screenshot', base_url='media/screenshot')
    for upload_file in files.values():
        fs.save(upload_file.name, upload_file)  # safe

    return render(request, '/success.html', {'filename': filename})
