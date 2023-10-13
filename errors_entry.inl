/*
 * =====================================================================================
 *
 *    Description:  Константы результатов функций
 *
 *        Company:  ProsoftSystems
 *
 * =====================================================================================
 */


ERR_ENTRY(RET_OK), ///< все хорошо
//счетчики
ERR_ENTRY(ERR_PROTO), ///< ошибка протокола, ответ содержит ошибки
ERR_ENTRY(ERR_NAK), ///< отказ выполнить команду
ERR_ENTRY(ERR_BAD_DATE), ///< некорректная дата
ERR_ENTRY(ERR_SMALL_PKT), ///< длина пакета меньше минимально допустимой
ERR_ENTRY(ERR_OVERFLOW), ///< переполнение буфера
ERR_ENTRY(ERR_BUSY), ///< устройство занято, повторить запрос позже
ERR_ENTRY(ERR_ADDR), ///< неверный адрес устройства
ERR_ENTRY(ERR_FUNC), ///< неверный код функции
ERR_ENTRY(ERR_CRC), ///< ошибка контрольной суммы пакета
ERR_ENTRY(ERR_TIMEOUT), ///< превышено время ожидания ответа или события
ERR_ENTRY(ERR_BAD_INTERVAL_DURATION), ///< длина интервала некорректная
ERR_ENTRY(ERR_TIME_NEAR_INTERVAL_BOUNDARY), ///< время слишком близко к границе интервала
ERR_ENTRY(ERR_NOTFOUND), ///< интервал не найден
ERR_ENTRY(ERR_BAD_HDR_CHKSUM), ///< нарушена котрольная сумма заголовка
ERR_ENTRY(ERR_PROFILE_INTEGRITY), ///< нарушение целостности профиля (сдвиг времени или выключение питания больше чем на интервал интегрирования)
ERR_ENTRY(ERR_CALC_PRF_TIME_PTR_FROM_HDR), ///< расчитываемое время из другого часа, чем используемый для расчета заголовок часа

ERR_ENTRY(ERR_SESSION_CLOSED), ///< нет открытой сессии, нужно открыть сессию с устройством
ERR_ENTRY(ERR_ACCESS_DENIED), ///< нет прав на выполнение действия

ERR_ENTRY(ERR_CONVERT), ///<  ошибка преобразования между типами

ERR_ENTRY(ERR_DATA_RESET), ///< данные сброшены (аннулированы)
ERR_ENTRY(ERR_NOT_READY), ///< данные не готовы, запрос следует повторить позже

ERR_ENTRY(ERR_REC_EMPTY), ///< запись данных или значение "пустые" (так сказать nullary value)
ERR_ENTRY(ERR_REC_INCOMPLETE), ///< запись данных неполная (незаконченная)
ERR_ENTRY(ERR_NO_MORE_DATA), ///< данных больше нет
ERR_ENTRY(ERR_MODULE_FAIL), ///< модуль неисправен

ERR_ENTRY(ERR_IO), ///< аппаратная ошибка ввода/вывода
ERR_ENTRY(ERR_DB), ///< ошибка уровня API БД
ERR_ENTRY(ERR_REBOOT), ///< контроллеру пришла команда на перезугрузку, ожидается завершение процессов
ERR_ENTRY(ERR_NO_MEM), ///< закончилась память
ERR_ENTRY(ERR_NO_DATA), ///< данных нет
ERR_ENTRY(ERR_DISCONNECTED), ///< попытка ввод/вывода на не подключенном устройстве (например, связь с удаленной стороной модема не установлена, или Raw Tcp нет соединения)
ERR_ENTRY(ERR_CONNECT), ///< ошибка подключения к удаленному устройству
ERR_ENTRY(ERR_EXCH_BREAK), ///< требование прервать обмен данными с устройством
ERR_ENTRY(ERR_PARAM_INVALID), ///< некоректное значение параметра

ERR_ENTRY(ERR_NOT_SUPPORTED), ///< неподдерживаемое оборудование или значение параметра
ERR_ENTRY(ERR_RANGE), ///< выход за пределы диапазона
ERR_ENTRY(ERR_NULL_PTR_DEREF), ///< разименование null указателя
ERR_ENTRY(ERR_LOCKCHAN), ///< ошибка захвата блокировки канала,
ERR_ENTRY(ERR_CORRTIME), ///< в процессе коррекции времени
ERR_ENTRY(ERR_PRIO), ///< сейчас активно более приоритетное устройство
ERR_ENTRY(ERR_SPECIAL_TIMESYNC), ///< специфическая синхронизация времени
ERR_ENTRY(ERR_SYNC), ///< использован синхрозапрос
ERR_ENTRY(ERR_BAD_DATA), ///< некорректные данные
ERR_ENTRY(ERR_UNKNOWN), ///< неизвестная ошибка
ERR_ENTRY(ERR_BUG), ///< самая "приятная" ошибка - наша ;-)
ERR_ENTRY(ERR_ACCESS_DEMAND), ///< высокоприоритетные данные ждут обработки

ERR_ENTRY(ERR_EXCEPTION) ///< начальное значение кода возврата исключения base_error, указывающее что код возврата не устанавливался
