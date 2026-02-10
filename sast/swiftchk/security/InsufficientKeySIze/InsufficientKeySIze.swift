//
//  ViewController.swift
//  CocoaPods
//
//  Created by Francis Lee on 2016. 4. 20..
//  Copyright © 2016년 Aircook. All rights reserved.

import UIKit
import CryptoSwift



class ViewController: UIViewController {

    //키
    let KEY: String = "01234567890123456789012345678901"

    //128bit (16자리)
    var KEY_128: String {
        get {
            return KEY.substringToIndex(KEY.startIndex.advancedBy(128 / 8))
        }
    }

    //256bit (32자리)
    var KEY_256: String {
        get {
            return KEY.substringToIndex(KEY.startIndex.advancedBy(256 / 8))
        }
    }

    //AES 128 암호화
    func encryptAES128(string: String) -> String {

        //1. 가장 간단한 형태, String의 extension 이용 ------------------------------------------------
        //let result: String = try! string.encrypt(AES(key: KEY_128, iv: KEY_128)).toBase64()!
        //1. ------------------------------------------------------------------------------------

        //2. NSData의 extension 이용 --------------------------------------------------------------
        //String을 NSData로 변환
        let plainData: NSData = string.dataUsingEncoding(NSUTF8StringEncoding)!
        //변환된 NSData를 AES로 암호화
        let encryptedData: NSData = try! plainData.encrypt(AES(key: KEY_128, iv: KEY_128))
        //암호하된 NSData를 base64 인코딩
        let result: String = encryptedData.base64EncodedStringWithOptions(NSDataBase64EncodingOptions(rawValue: 0))
        //2. ------------------------------------------------------------------------------------

        //3. blockMode, padding 제어, defaul값이 CBC/PKCS7 ----------------------------------------
        //let encryptedBytes: [UInt8] = try! AES(key: KEY_128, iv: KEY_128, blockMode: .CBC).encrypt([UInt8](string.utf8), padding: PKCS7())
        //let result: String = NSData(bytes: encryptedBytes, length:encryptedBytes.count).base64EncodedStringWithOptions(NSDataBase64EncodingOptions(rawValue: 0))
        //3. ------------------------------------------------------------------------------------

        return result

    }

    //AES128 복호화
    func decryptAES128(string: String) -> String {

        //암호회된 문자를 base64 디코딩
        let encryptedData: NSData = NSData(base64EncodedString: string, options: NSDataBase64DecodingOptions(rawValue: 0))!
        //디코딩된 NSData를 AES 복호화
        let plainData: NSData = try! encryptedData.decrypt(AES(key: KEY_128, iv: KEY_128))
        //복호화된 NSData를 Strin으로 변환
        let result: String = String(data: plainData, encoding: NSUTF8StringEncoding)!

        return result

    }

    //AES 256 암호화
    func encryptAES256(string: String) -> String {

        let result: String = try! string.encrypt(AES(key: KEY_256, iv: KEY_128)).toBase64()!

        return result

    }

    //AES256 복호화
    func decryptAES256(string: String) -> String {

        let result: String = try! string.decryptBase64ToString(AES(key: KEY_256, iv: KEY_128))

        return result

    }

    //SHA256 해쉬 함수 암호화
    func encryptSHA256(string: String) -> String {

        //16진수, Hex
        //let result: String = string.sha256()
        let plainData: NSData = string.dataUsingEncoding(NSUTF8StringEncoding)!
        let encryptedData: NSData = plainData.sha256()!
        //base64 인코딩
        let result: String = encryptedData.base64EncodedStringWithOptions(NSDataBase64EncodingOptions(rawValue: 0))

        return result

    }

    override func viewDidLoad() {

        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.

        let str1: String = "암호화되지 않은 문자"
        print("plain : \(str1)")

        let str2: String = self.encryptAES128(str1)
        print("AES128 encrypted : \(str2)")

        let str3: String = self.decryptAES128(str2)
        print("AES128 decrypted : \(str3)")

        let str4: String = self.encryptAES256(str1)
        print("AES256 encrypted : \(str4)")

        let str5: String = self.decryptAES256(str4)
        print("AES256 decrypted : \(str5)")

        let str6: String = self.encryptSHA256(str1)
        print("SHA256 encrypted : \(str6)")

    }

    override func didReceiveMemoryWarning() {

        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.

    }

}

