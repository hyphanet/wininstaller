;
; Translation helper
;
; This file contains functions used to translate the GUI.
;

;
; Include translations
;
#Include ..\src_translationhelper\Include_Lang_da.inc								; Include Danish (da) translation
#Include ..\src_translationhelper\Include_Lang_fr.inc								; Include French (fr) translation

InitTranslations()
{
	global

	_LangArray := 1												; Set initial position for languages array

	; AddLanguage() arguments: <localized language name> <language load function name from language file> <windows language code (see http://www.autohotkey.com/docs/misc/Languages.htm)>
	AddLanguage("English","","")										; Load English (en) translation (dummy)
	AddLanguage("Dansk","LoadLanguage_da","0406")
	AddLanguage("Français","LoadLanguage_fr","040c+080c+0c0c+100c+140c+180c")				; Make default for all variations of French

	LoadLanguage(LanguageCodeToID(A_Language))								; Load language matching OS language (will fall back to English if no match)
}

AddLanguage(_Name, _LoadFunction, _LanguageCode)
{
	global

	_LanguageNames%_LangArray% := _Name
	_LanguageLoadFunctions%_LangArray% := _LoadFunction
	_LanguageCodes%_LangArray% := _LanguageCode

	_LangArray++
}

LoadLanguage(_LoadNum)
{
	global

	_LangNum := _LoadNum
	_TransArray := 1
	_LoadFunction := _LanguageLoadFunctions%_LoadNum%

	If (_LoadFunction <> "")
	{
		%_LoadFunction%()
	}
}

LanguageCodeToID(_LanguageCode)
{
	global

	Loop % _LangArray-1
	{
		IfInString, _LanguageCodes%A_Index%, %_LanguageCode%
		{
			return A_Index
		}
	}

	return 1												; Language 1 should always be the default language, so use that if no match above
}

Trans_Add(_OriginalText, _TranslatedText)
{
	global

	_OriginalTextArray%_TransArray% := _OriginalText
	_TranslatedTextArray%_TransArray% := _TranslatedText

	_TransArray++
}

Trans(_OriginalText)
{
	global

	Loop % _TransArray-1
	{
		If (_OriginalText = _OriginalTextArray%A_Index%)
		{
			return UTF82Ansi(_TranslatedTextArray%A_Index%)
		}
	}

	return _OriginalText
}

UTF82Ansi(zString)
{
	Ansi2Unicode(zString, wString, 65001)
	Unicode2Ansi(wString, sString, 0)
	Return sString
}

Ansi2Unicode(ByRef sString, ByRef wString, CP = 0)
{
     nSize := DllCall("MultiByteToWideChar"
      , "Uint", CP
      , "Uint", 0
      , "Uint", &sString
      , "int",  -1
      , "Uint", 0
      , "int",  0)

   VarSetCapacity(wString, nSize * 2)

   DllCall("MultiByteToWideChar"
      , "Uint", CP
      , "Uint", 0
      , "Uint", &sString
      , "int",  -1
      , "Uint", &wString
      , "int",  nSize)
}

Unicode2Ansi(ByRef wString, ByRef sString, CP = 0)
{
     nSize := DllCall("WideCharToMultiByte"
      , "Uint", CP
      , "Uint", 0
      , "Uint", &wString
      , "int",  -1
      , "Uint", 0
      , "int",  0
      , "Uint", 0
      , "Uint", 0)

   VarSetCapacity(sString, nSize)

   DllCall("WideCharToMultiByte"
      , "Uint", CP
      , "Uint", 0
      , "Uint", &wString
      , "int",  -1
      , "str",  sString
      , "int",  nSize
      , "Uint", 0
      , "Uint", 0)
}

